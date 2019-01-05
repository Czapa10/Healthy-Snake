#include "gameState.hpp"
#include "snake.hpp"
#include "gameOverState.hpp"

#include <iostream>

namespace States
{


GameState::GameState(Game::GameDataRef _data) : data(_data)
,statisticsBar(data)
{
}

void GameState::init()
{
    background.setTexture(data->textures.get(Textures::gameBackground));

    clearTiles();
    settingFood();
}

void GameState::input()
{
    snake.control();
}

void GameState::update(sf::Time deltaTime)
{
    if(freeze){
        if(timeToShowGameOverScreen.getElapsedTime().asSeconds() > 1.1){
            std::unique_ptr<States::GameOverState> toStack(new States::GameOverState(data));
            data->stateStack.pushState(std::move(toStack));
        }

        return;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
        snake.grow();
    }

    ///set sprites
    clearTiles();

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

        bool isTeleporting = checkIsTeleporting(previous, x, y);

        ///after teleport turn transformations
        if((next.y + 1 != y)&&(next.y - 1 != y)&&(next.y != y)){
        next.y = -next.y;
        if(next.y == 0)
            next.y = 35;
        }
        else if((next.x + 1 != x)&&(next.x - 1 != x)&&(next.x != x)){
            next.x = -next.x;
            if(next.x == 0)
                next.x = 35;
        }

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

    foodUpdate();

    ///snake move
    if(clock.getElapsedTime().asSeconds() > snake.getSpeed()){
        snake.move();
        snake.grow();
        clock.restart();

        ///check collision
        if(snake.isCollideWithItself(tiles)){
            freeze = true;
            timeToShowGameOverScreen.restart();
        }
    }
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

    statisticsBar.draw(points, snake.getLength(), snake.getInStomach());

    data->window.display();
}

//*************************************************************************

void GameState::clearTiles()
{
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 24; j++){
            tiles[i][j] = Textures::nothing;
            spriteRotation[i][j] = GameElements::Direction::up;
        }
    }
}

void GameState::settingFood()
{
    for(int i = 0; i < numberOfMealsOnTheScreen; ++i){
        GameElements::Food meal;
        food.push_back(meal);
    }
}

void GameState::foodUpdate()
{
    int i{};
    for(auto & meal : food){

        tiles[meal.getPosition().x][meal.getPosition().y] = meal.getTextureID();

        ///eating meal and meal changes its position
        bool changePos{false};

        if((snake.getDirection() == GameElements::Direction::left)&&
            (snake.bodyParts[0].pos.x == meal.getPosition().x)&&
            (snake.bodyParts[0].pos.y == meal.getPosition().y)){
                changePos = true;
        }
        else if((snake.getDirection() == GameElements::Direction::right)&&
            (snake.bodyParts[0].pos.x == meal.getPosition().x)&&
            (snake.bodyParts[0].pos.y == meal.getPosition().y)){
                changePos = true;
        }
        else if((snake.getDirection() == GameElements::Direction::up)&&
            (snake.bodyParts[0].pos.x == meal.getPosition().x)&&
            (snake.bodyParts[0].pos.y == meal.getPosition().y)){
                changePos = true;
        }
        else if((snake.getDirection() == GameElements::Direction::down)&&
            (snake.bodyParts[0].pos.x == meal.getPosition().x)&&
            (snake.bodyParts[0].pos.y == meal.getPosition().y)){
                changePos = true;
        }

        if(changePos){
            snake.eat(meal.getWeight());
            points += meal.getPoints();

            if(food.size() * 4 > 768 - snake.getLength()){
                food.erase(food.begin() + i);
                std::cout<<food.size()<<std::endl;
            }
            else{
                for(;;){
                    meal.setRandomPos();

                    bool getOut{true};

                    for(auto part : snake.bodyParts){
                        if(meal.getPosition() == part.pos){
                            getOut = false;
                            break;
                        }
                    }

                    if(getOut){
                        for(int j = 0; j < i; ++j){
                            if(meal.getPosition() == food[j].getPosition()){
                                getOut = false;
                                break;
                            }
                        }
                    }

                    if(getOut){
                        for(int j = i + 1; j < food.size(); ++j){
                            if(meal.getPosition() == food[j].getPosition()){
                                getOut = false;
                                break;
                            }
                        }
                    }

                    if(getOut)
                        break;
                }
            }
        }
        ++i;
    }
}

bool GameState::checkIsTeleporting(sf::Vector2i previous, int x, int y)
{
    if((x + 1 != previous.x)&&(x - 1 != previous.x)
    &&(x != previous.x)&&(x != previous.x)
    ||(y + 1 != previous.y)&&(y - 1 != previous.y)
    &&(y != previous.y)&&(y != previous.y)){
        return true;
    }
    return false;
}


}
