//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "PlaceHolder.h"

PlaceHolder::PlaceHolder(sf::RectangleShape* backGround)
{
    this->backGround=backGround;
}

sf::RectangleShape* PlaceHolder::get_backGround()
{
    return backGround;
}


void PlaceHolder::drawUI(sf::RenderWindow& window) {
window.draw(*backGround);
for(auto text:labels)
{
    window.draw(text);
}
}
