#include "textButtonContainer.hpp"

namespace GUI
{


TextButtonContainer::TextButtonContainer(Game::GameDataRef data, Fonts::ID fontID, std::vector<std::string> texts, int numberOfButtons, int spaceBetweenButtons, unsigned int fontSize, sf::Vector2i offset, bool areButtonsCentered)
:data(data)
,snake(data, 4u)
,numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,offset(offset)
,fontSize(fontSize)
,scaleFactor(0)
{
    buttons.reserve(numberOfButtons);

    int Hmargin = (SCREEN_HEIGHT - (1.3 * fontSize * numberOfButtons + (numberOfButtons - 1) * spaceBetweenButtons) ) / 2;

    int centerValue = areButtonsCentered ? 4 : 2;

    for(int i = 0; i < numberOfButtons; ++i){
        buttons.emplace_back(
            Button(
                data,
                fontID,
                texts[i],
                sf::Vector2f(
                    SCREEN_WIDTH / 2 - fontSize * texts[i].size() / centerValue + offset.x, // <- This algorithm makes problem
                    i * (1.3 * fontSize + spaceBetweenButtons) + offset.y + Hmargin
                            ),
                fontSize
            )
        );

        std::cout<<i<<"x: "<<SCREEN_WIDTH / 2 - ( fontSize * texts[i].size()) / 2 + offset.x<<std::endl;
    }


}

void TextButtonContainer::input()
{
    keyboardControls();
    mouseControls();
}

void TextButtonContainer::update()
{
    ButtonContainer::update();
    ///make snake::update() overloaded function
    //snake.update(buttons[0].getSprite().getPosition(), buttonSize, buttons[isOnButtonNr].getSprite().getPosition().y, scaleFactor);
}

void TextButtonContainer::display()
{
    snake.display();

    for(auto &button : buttons){
        button.display();
    }
}

TextButton& TextButtonContainer::operator[](unsigned int numberOfButton)
{
    if(numberOfButton >= buttons.size()){
        std::cout<<"This button container has "<<buttons.size()<<" buttons ( 0 - "<<buttons.size() - 1<<
        ") So you can't get reference to "<<numberOfButton<<std::endl;
    }
    return;

    return buttons[numberOfButton];
}

void SpriteButtonContainer::mouseControls()
{
    currentMousePos = sf::Mouse::getPosition(data->window);

    #if 0
    if(currentMousePos != lastMousePos){
        for(int i = 0; i < numberOfButtons; ++i){
            if(buttons[i].isMouseOnButton(currentMousePos))
                isOnButtonNr = i;
        }
    }

    for(auto button : buttons){
        if((button.isClicked(currentMousePos))&&(timeSinceLastClick.getElapsedTime().asSeconds() > 0.23))
            signal = isOnButtonNr;
    }
    #endif // 0

    lastMousePos = currentMousePos;
}


}
