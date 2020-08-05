//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "Page.h"

Page::Page(sf::RenderWindow* window,const int upperBarheight)
{
    this->window=window;
    background=new sf::RectangleShape();
    background->setPosition({float (window->getSize().x/6),float(upperBarheight)});
    background->setSize({window->getSize().x-float (window->getSize().x/6),float(window->getSize().y-upperBarheight)});
    background->setFillColor({10,200,0});

}

void Page::drawUI() {
window->draw(*background);
for(int i=0;i<shapes.size();i++)
{
    window->draw(*shapes[i]);
}
}
