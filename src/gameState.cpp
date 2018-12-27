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

        sf::Vector2i pervious = snake.bodyParts[it - 1].pos;
        sf::Vector2i next = snake.bodyParts[it + 1].pos;

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
        if((bodyPart.pos.x + 1 != pervious.x)&&(bodyPart.pos.x - 1 != pervious.x)
        &&(bodyPart.pos.x != pervious.x)&&(bodyPart.pos.x != pervious.x)
        ||(bodyPart.pos.y + 1 != pervious.y)&&(bodyPart.pos.y - 1 != pervious.y)
        &&(bodyPart.pos.y != pervious.y)&&(bodyPart.pos.y != pervious.y)){
            isTeleporting = true;
        }

        bool isNextTeleporting{false};
        if((next.x + 1 != bodyPart.pos.x)&&(next.x - 1 != bodyPart.pos.x)
        &&(next.x != bodyPart.pos.x)&&(next.x != bodyPart.pos.x)
        ||(next.y + 1 != bodyPart.pos.y)&&(next.y - 1 != bodyPart.pos.y)
        &&(next.y != bodyPart.pos.y)&&(next.y != bodyPart.pos.y)){
            isNextTeleporting = true;
        }

        std::cout<<isNextTeleporting<<" ";

        ///making snake turn body sprite
        if((it != 0)&&(it != snake.getLength() - 1)){ //if this body part is not head and tail
            if(isNextTeleporting){
                //std::cout<<isNextTeleporting<<"IS NEXT TELEPORING = TRUE"<<std::endl;
                if((pervious.y < bodyPart.pos.y)&&(next.y == bodyPart.pos.y)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(next.x < bodyPart.pos.x){
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                }
                else if((pervious.y < bodyPart.pos.y)&&(next.y == bodyPart.pos.y)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(next.x > bodyPart.pos.x){
                            spriteRotation[x][y] = GameElements::Direction::up;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                }
                else if((pervious.x > bodyPart.pos.x)&&(next.x == bodyPart.pos.x)){
                        std::cout<<"                            --___***___--"<<std::endl;
                    if(next.y < bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::right;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::up;
                    }
                }
                else if((pervious.x < bodyPart.pos.x)&&(next.x == bodyPart.pos.x)){
                        std::cout<<"                            --___***___--"<<std::endl;
                    if(next.y > bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::down;
                    }
                    else{
                        spriteRotation[x][y] = GameElements::Direction::left;
                    }
                }
            }//*****************************************************************
            else{
                //std::cout<<isNextTeleporting<<"is next teleporting = false"<<std::endl;

                if((pervious.y > bodyPart.pos.y)&&(next.y == bodyPart.pos.y)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(isTeleporting){
                        if(next.x < bodyPart.pos.x){
                            spriteRotation[x][y] = GameElements::Direction::left;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::up;
                        }
                    }
                    else{
                        if(next.x < bodyPart.pos.x){
                            spriteRotation[x][y] = GameElements::Direction::down;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::right;
                        }
                    }

                }
                else if((pervious.y < bodyPart.pos.y)&&(next.y == bodyPart.pos.y)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(isTeleporting){
                        if(next.x > bodyPart.pos.x){
                            spriteRotation[x][y] = GameElements::Direction::right;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::down;
                        }
                    }
                    else{
                        if(next.x > bodyPart.pos.x){
                            spriteRotation[x][y] = GameElements::Direction::up;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::left;
                        }
                    }
                }
                else if((pervious.x > bodyPart.pos.x)&&(next.x == bodyPart.pos.x)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(isTeleporting){
                        if(next.y < bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::left;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::down;
                        }
                    }
                    else{
                        if(next.y < bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::up;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::right;
                        }
                    }
                }
                else if((pervious.x < bodyPart.pos.x)&&(next.x == bodyPart.pos.x)){
                    tiles[x][y] = Textures::snakeTurnBody;

                    if(isTeleporting){
                        if(next.y > bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::right;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::up;
                        }
                    }
                    else{
                        if(next.y > bodyPart.pos.y){
                        spriteRotation[x][y] = GameElements::Direction::down;
                        }
                        else{
                            spriteRotation[x][y] = GameElements::Direction::left;
                        }
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
