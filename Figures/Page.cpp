//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "Page.h"

Page::Page(sf::RectangleShape* backGround)
{
    this->backGround=backGround;
}

sf::RectangleShape* Page::get_backGround()
{
    return backGround;
}


void Page::drawUI(sf::RenderWindow& window) {
window.draw(*backGround);

}
