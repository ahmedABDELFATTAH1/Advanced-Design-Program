//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_FIGURE_H
#define UNTITLED2_FIGURE_H
#include"../common.h"
class Figure{
protected:
    color_comp color;
    point p1;
    point p2;
    bool isFilled;
    sf::Texture* shapeTexture;
    bool needUpdate;
public:
    static int numFigures;
    Figure(color_comp col,point p1,point p2,bool Filled,sf::Texture* texture);
    virtual sf::Shape& getUI()=0;
    virtual void setUI()=0;
    virtual void printDimentions()=0;
    virtual void setDimentions()=0;
    void setTexure(sf::Shape* shape);
    ~Figure();

};


#endif //UNTITLED2_FIGURE_H
