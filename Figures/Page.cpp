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
    selectedShape= nullptr;

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

bool Page::setSelectedShape(int x, int y) {
    for(int i=0;i<shapes.size();i++)
    {
        if(shapes[i]->getGlobalBounds().contains(x,y))
        {
            selectedShape=shapes[i];
            selectedColor.r=selectedShape->getOutlineColor().r;
            selectedColor.g=selectedShape->getOutlineColor().g;
            selectedColor.b=selectedShape->getOutlineColor().b;
            return true;
        }
    }
    return false;
}

sf::Shape *Page::getSelectedShape() {
    return selectedShape;
}

void Page::deleteSelectedShape() {
    auto itr=shapes.begin();
    for(;*itr!=selectedShape;itr++);
    shapes.erase(itr);
    delete *itr;
}

void Page::unSelect() {
selectedShape->setOutlineColor({selectedColor.r,selectedColor.g,selectedColor.b});
selectedShape= nullptr;
}



