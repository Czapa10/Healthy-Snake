#include "gameState.hpp"
#include "snake.hpp"
#include "gameOverState.hpp"

#include <iostream>

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
{
}

void GameState::init()
{
    background.setTexture(data->textures.get(Textures::gameBackground));

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
        }
    }
}

void GameState::input()
{
    snake.control();
}

void GameState::update(sf::Time deltaTime)
{
    if(freeze){
        std::cout<<"to game over screen: "<<2 - timeToShowGameOverScreen.getElapsedTime().asSeconds()<<std::endl;

        if(timeToShowGameOverScreen.getElapsedTime().asSeconds() > 2){
            std::unique_ptr<States::GameOverState> toStack(new States::GameOverState(data));
            data->stateStack.pushState(std::move(toStack));
        }

        return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
        snake.grow();
    }

    ///set sprites
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
            spriteRotation[i][j] = GameElements::Direction::up;
        }
    }

    std::cout<<"is teleporting: ";

    int it{};//iterator
    for(auto & bodyPart : snake.bodyParts){
        int x = bodyPart.pos.x;
        int y = bodyPart.pos.y;

        sf::Vector2i previous = snake.bodyParts[it - 1].pos; //(to head)
        sf::Vector2i next = snake.bodyParts[it + 1].pos; //(to tail)

        spriteRotation[x][y] = bodyPart.direction;

        if(it == 0){
            tiles[x][y] = Textures::snakeHead;
        }
        else if(it == snake.getLength() - 1){
            tiles[x][y] = Textures::snakeTail;
            spriteRotation[x][y] = snake.bodyParts[snake.getLength() - 2].direction;
        }
        else{
            tiles[x][y] = Textures::snakeStraightBody;
        }

        ///checking is snake teleporting
        bool isTeleporting{false};
        if((x + 1 != previous.x)&&(x - 1 != previous.x)
        &&(x != previous.x)&&(x != previous.x)
        ||(y + 1 != previous.y)&&(y - 1 != previous.y)
        &&(y != previous.y)&&(y != previous.y)){
            isTeleporting = true;
        }

        if((next.y + 1 != y)&&(next.y - 1 != y)&&(next.y != y)){
            previous.y = -previous.y;
        }
        else if((next.x + 1 != x)&&(next.x - 1 != x)&&(next.x != x)){
            previous.x = -previous.x;
        }

        std::cout<<isTeleporting<<" ";

        ///making snake turn body sprite
        if((it != 0)&&(it != snake.getLength() - 1)){ //if this body part is not head and tail

            if((previous.y > y)&&(next.y == y)){
                tiles[x][y] = Textures::snakeTurnBody;

                if(isTeleporting){
                    if(next.x < x){
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::up;
                    }
                }
                else{
                    if(next.x < x){
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                }

            }
            else if((previous.y < y)&&(next.y == y)){
                tiles[x][y] = Textures::snakeTurnBody;

                if(isTeleporting){
                    if(next.x < x){
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                }
                else{
                    if(next.x < x){
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::up;
                    }
                }
            }
            else if((previous.x > x)&&(next.x == x)){
                tiles[x][y] = Textures::snakeTurnBody;

                if(isTeleporting){
                    if(next.y < y){
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                }
                else{
                    if(next.y < y){
                    spriteRotation[x][y] = GameElements::Direction::up;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                }
            }
            else if((previous.x < x)&&(next.x == x)){
                tiles[x][y] = Textures::snakeTurnBody;

                if(isTeleporting){
                    if(next.y < y){
                        spriteRotation[x][y] = GameElements::Direction::up;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                }
                else{
                    if(next.y < y){
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                }
            }
        }
        ++it;
    }

    std::cout<<std::endl;

    tiles[food.getPosition().x][food.getPosition().y] = Textures::appleRed;

    ///eating food and food changes its position
    bool changePos{false};

    if((snake.getDirection() == GameElements::Direction::left)&&
        (snake.bodyParts[0].pos.x == food.getPosition().x)&&
        (snake.bodyParts[0].pos.y == food.getPosition().y)){
            changePos = true;
    }
    else if((snake.getDirection() == GameElements::Direction::right)&&
        (snake.bodyParts[0].pos.x == food.getPosition().x)&&
        (snake.bodyParts[0].pos.y == food.getPosition().y)){
            changePos = true;
    }
    else if((snake.getDirection() == GameElements::Direction::up)&&
        (snake.bodyParts[0].pos.x == food.getPosition().x)&&
        (snake.bodyParts[0].pos.y == food.getPosition().y)){
            changePos = true;
    }
    else if((snake.getDirection() == GameElements::Direction::down)&&
        (snake.bodyParts[0].pos.x == food.getPosition().x)&&
        (snake.bodyParts[0].pos.y == food.getPosition().y)){
            changePos = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))///only for testing
        changePos = true;

    if(changePos){
        for(;;){
            food.setRandomPos();
            snake.grow();

            bool getOut{true};

            for(auto part : snake.bodyParts){
                if(food.getPosition() == part.pos){
                    getOut = false;
                    break;
                }
            }

            if(getOut)
                break;
        }
    }

    ///snake move
    if(clock.getElapsedTime().asSeconds() > snake.getSpeed()){
        snake.move();
        clock.restart();

        ///check collision
        if(snake.isCollideWithItself(tiles)){
            freeze = true;
            timeToShowGameOverScreen.restart();
        }
    }



    ///test
    /*for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            if(tiles[i][j] == Textures::nothing)
                std::cout<<"not  ";
            else if(tiles[i][j] == Textures::snakeStraightBody)
                std::cout<<"sss  ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n\n\n";*/
    ///test
}

void GameState::draw()
{
    data->window.clear();

    data->window.draw(background);

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            if(tiles[i][j] != Textures::nothing){
                sf::Sprite sprite;
                sprite.setTexture(data->textures.get(tiles[i][j]));
                sprite.setPosition(sf::Vector2f(i * 32 + 16, /*48 +*/ j * 32 + 16));

                sprite.setOrigin(16.f, 16.f);
                if(spriteRotation[i][j] == GameElements::Direction::left){
                    sprite.rotate(-90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::right){
                    sprite.rotate(90.f);
                }
                else if(spriteRotation[i][j] == GameElements::Direction::down){
                    sprite.rotate(180.f);
                }

                data->window.draw(sprite);
            }
        }
    }

    data->window.display();
}


}
