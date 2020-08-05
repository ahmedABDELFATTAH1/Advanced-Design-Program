//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#include "Button.h"

bool Button::oNSelected(point p) {
    static int count=0;
  if(rectangle->getGlobalBounds().contains(p.x,p.y))
  {
    return true;
  }
else{
    return false;
}

}

Button::Button(sf::RectangleShape* rec, Text* tex, std::string btn_name):rectangle(rec),text(tex),buttonName(btn_name) {

selected= false;

}


bool Button::isSelected() {
   return selected;
}


Button::~Button() {
    delete rectangle;
    delete text;
}

void Button::drawButton(sf::RenderWindow *window) {
    window->draw(*rectangle);
    if(text)
    {
        text->drawText(window);
    }

}
void Button::changeSelectedUI()
{
    if(selected)
    {
        rectangle->setFillColor({200,200,200});
    }else{
        rectangle->setFillColor({100,100,100});
    }
}

void Button::toggleSelected() {
    if(!selected)
    {
        selected= true;
    }else{
        selected= false;

    }
}

void Button::changePosition(point p) {
    rectangle->setPosition(p.x,p.y);
    text->changePosition({int(p.x+rectangle->getSize().x/5),p.y});
}

void Button::changeSelectedTexture() {
    if(selected)
    {
        rectangle->setTexture(texture2);
    }else{
        rectangle->setTexture(texture1);
    }
}

void Button::setTextures(sf::Texture *tex2) {
    texture1=rectangle->getTexture();
    texture2=tex2;
}

std::string Button::getName() {
    return buttonName;
}
