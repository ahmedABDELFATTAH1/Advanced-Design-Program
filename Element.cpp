//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#include "Element.h"

bool Element::oNSelected(point p) {
  if(rectangle->getGlobalBounds().contains(p.x,p.y))
  {
    return true;
  }
else{
    return false;
}

}

Element::Element(sf::RectangleShape* rec, Text* tex, std::string btn_name): rectangle(rec), text(tex), buttonName(btn_name) {

selected= false;

}


bool Element::isSelected() {
   return selected;
}


Element::~Element() {
    delete rectangle;
    delete text;
}

void Element::drawButton(sf::RenderWindow *window) {
    window->draw(*rectangle);
    if(text)
    {
        text->drawText(window);
    }

}
void Element::changeSelectedUI()
{
    if(selected)
    {
        rectangle->setFillColor({20,20,20});
    }else{
        rectangle->setFillColor({255,255,255});
    }
}

void Element::toggleSelected() {
    if(!selected)
    {
        selected= true;
    }else{
        selected= false;

    }
}

void Element::changePosition(point p) {
    rectangle->setPosition(p.x,p.y);
    text->changePosition({int(p.x+rectangle->getSize().x/5),p.y});
}

void Element::changeSelectedTexture() {
    if(selected)
    {
        rectangle->setTexture(texture2);
    }else{
        rectangle->setTexture(texture1);
    }
}

void Element::setTextures(sf::Texture *tex2) {
    texture1=rectangle->getTexture();
    texture2=tex2;
}



std::string Element::getName() {
    return buttonName;
}
