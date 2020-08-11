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
    background->setFillColor({255,255,255}); 

}

void Page::drawUI() {
window->draw(*background);
for(int i=0;i<shapes.size();i++)
{
    window->draw(*shapes[i]);
}
}

void Page::addShape(sf::Shape *shape) {
shapes.push_back(shape);
}

Page::~Page() {

}
