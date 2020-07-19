//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_RECTANGLE_H
#define UNTITLED2_RECTANGLE_H

#include "common.h"
#include "Figure.h"
class Rectangle : public Figure{
protected:
    sf::RectangleShape* rectangleShape;
    float width,high;

public:
    Rectangle(color_comp col,point p1,point p2);
    virtual void setDimentions();
    sf::RectangleShape& getUI();
    virtual void printDimentions();
    virtual void setUI();

};


#endif //UNTITLED2_RECTANGLE_H
