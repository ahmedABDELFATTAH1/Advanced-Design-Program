//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#include <cmath>
#include "Circle.h"
Circle::Circle(color_comp col, point p1,point p2,bool Filled,sf::Texture* texture):Figure{col,p1,p2,Filled,texture}{
    circleShape= nullptr;
    setDimentions();
    setUI();
};

sf::CircleShape& Circle::getUI()
{
return *circleShape;
}

void Circle::setUI() {
    setDimentions();
    delete circleShape;
    circleShape=new sf::CircleShape(radius);
    sf::Color shapeColor({color.r,color.g,color.b});
    circleShape->setPointCount (100);
    if(isFilled)
    {
        circleShape->setFillColor(shapeColor);
    } else{
        circleShape->setOutlineThickness(3);
        circleShape->setOutlineColor(shapeColor);
    }

    circleShape->setPosition(p1.x,p1.y);

}

void Circle::setDimentions() {
    radius=-sqrt(pow(p1.y - p2.y,2)+pow(p1.x - p2.x,2));
}
void Circle::printDimentions()
{
    std::cout<<"Radius value is "<<radius<<std::endl;
    std::cout<<"p1 value is ("<<p1.x<<","<<p1.y<<")"<<std::endl;
    std::cout<<"p2 value is ("<<p2.x<<","<<p2.y<<")"<<std::endl;
}

