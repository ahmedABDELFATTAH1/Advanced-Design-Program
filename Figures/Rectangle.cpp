//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//



#include "Rectangle.h"
Rectangle::
Rectangle(color_comp col,point p1,point p2,bool Filled,sf::Texture* texture):Figure{col,p1,p2,Filled,texture}{
    rectangleShape= new sf::RectangleShape();
    setUI();
};

sf::RectangleShape& Rectangle::getUI()
{
    return *rectangleShape;
}

void Rectangle::setUI() {
    setDimentions();
    if(shapeTexture)
    {
        Figure::setTexure(rectangleShape);
    }
    else{
        sf::Color shapeColor({color.r,color.g,color.b});
        rectangleShape->setFillColor(shapeColor);
    }
    rectangleShape->setSize({width,high});
    rectangleShape->setPosition(p1.x,p1.y);
}

void Rectangle::setDimentions() {
this->width=-(p1.x-p2.x);
this->high=-(p1.y-p2.y);
}


void Rectangle::printDimentions() {
    std::cout<<"p1 value is ("<<p1.x<<","<<p1.y<<")"<<std::endl;
    std::cout<<"p2 value is ("<<p2.x<<","<<p2.y<<")"<<std::endl;
    std::cout<<"width value is "<<width<<std::endl;
    std::cout<<"high value is "<<high<<std::endl;
}

bool Rectangle::isSelected(int cursorX,int cursorY) {


}
