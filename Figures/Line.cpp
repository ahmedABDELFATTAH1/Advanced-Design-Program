//
// Created by ahmed on ١٩‏/٧‏/٢٠٢٠.
//

#include <cmath>
#include "Line.h"


Line::Line(color_comp col,point p1,point p2):Rectangle{col,p1,p2}{
    rectangleShape= nullptr;
    setUI();
}


void Line::setDimentions() {
angle= std::atan2(p1.y - p2.y, p1.x - p2.x);
angle=(angle*180/M_PI);
diameter=-sqrt(pow(p1.y - p2.y,2)+pow(p1.x - p2.x,2));
}


void Line::printDimentions() {
    std::cout<<"Angle value is "<<angle<<std::endl;
    std::cout<<"Diameter value is "<<diameter<<std::endl;
    std::cout<<"p1 value is ("<<p1.x<<","<<p1.y<<")"<<std::endl;
    std::cout<<"p2 value is ("<<p2.x<<","<<p2.y<<")"<<std::endl;
}

void Line::setUI() {
    setDimentions();
    delete rectangleShape;
    rectangleShape=new sf::RectangleShape();
    rectangleShape->setSize({diameter,thickness});
    rectangleShape->setRotation(angle);
    sf::Color shapeColor({color.r,color.g,color.b});
    rectangleShape->setFillColor(shapeColor);
    rectangleShape->setPosition(p1.x,p1.y);
}
