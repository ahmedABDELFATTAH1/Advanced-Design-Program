//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#include "Figure.h"
Figure::Figure(color_comp col,point p1,point p2,bool Filled,sf::Texture* texture= nullptr){
this->color=col;
this->p1=p1;
this->p2=p2;
isFilled=Filled;
if(texture!= nullptr)
    shapeTexture=texture;

}
void Figure::setTexure(sf::Shape* shape)
{
    shape->setTexture(shapeTexture);
}

Figure::~Figure() {

}
