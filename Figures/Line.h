//
// Created by ahmed on ١٩‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_LINE_H
#define UNTITLED2_LINE_H
#include "Rectangle.h"

class Line :public Rectangle{
private:
float angle;
float diameter;
constexpr static const float thickness=5;
void setDimentions();
public:
Line(color_comp col,point p1,point p2,bool Filled,sf::Texture* texture);
void printDimentions();
void setUI();


};


#endif //UNTITLED2_LINE_H
