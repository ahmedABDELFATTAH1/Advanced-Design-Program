//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_COMMON_H
#define UNTITLED2_COMMON_H
#include <SFML/Graphics.hpp>
#include<algorithm>
#include<iostream>
class point{
public:
    int x,y;

    void operator =(const sf::Vector2<int>& v)
    {
        this->x=v.x;
        this->y=v.y;
    }


};


struct color_comp{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
#endif //UNTITLED2_COMMON_H
