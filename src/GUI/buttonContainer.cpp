#include "buttonContainer.hpp"

namespace GUI
{


ButtonContainer::ButtonContainer(int numberOfButtons, int spaceBetweenButtons, sf::Vector2i buttonSize, sf::Vector2i offset, bool isRegular)
:numberOfButtons(numberOfButtons)
,spaceBetweenButtons(spaceBetweenButtons)
,buttonSize(buttonSize)
,offset(offset)
,isRegular(isRegular)
{
}


}
