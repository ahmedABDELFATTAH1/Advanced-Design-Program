//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_CIRCLE_H
#define UNTITLED2_CIRCLE_H
#include "Figure.h"

class Circle : public Figure{
private:
    int radius;
    point center;
    sf::CircleShape* circleShape;
public:
    Circle(color_comp col, point p1,point p2,bool Filled,sf::Texture* texture);
    sf::CircleShape& getUI();
    void setUI();
    void setDimentions();
    void printDimentions();
};

#endif //UNTITLED2_CIRCLE_H
