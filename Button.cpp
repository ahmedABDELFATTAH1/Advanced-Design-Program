//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#include "Button.h"

bool Button::oNSelected(point p) {
    static int count=0;
  if(rectangle->getUI().getGlobalBounds().contains(p.x,p.y))
  {
     toggleSelected();
  }
  return selected;
}

Button::Button(Rectangle* rec, Text* tex, std::string btn_name):rectangle(rec),text(tex),buttonName(btn_name) {

selected= false;

}


bool Button::isSelected() {
   return selected;
}


Button::~Button() {

}

void Button::drawButton(sf::RenderWindow *window) {
    window->draw(rectangle->getUI());
    if(text)
    {
        text->drawText(window);
    }

}

void Button::toggleSelected() {
    if(!selected)
    {
        selected= true;
        std::cout<<(bool)selected<<std::endl;
        rectangle->getUI().setOutlineThickness(3);
        rectangle->getUI().setOutlineColor(sf::Color::Red);

    }else{
        selected= false;
        rectangle->getUI().setOutlineThickness(0);
        std::cout<<(bool)selected<<std::endl;
    }
}
