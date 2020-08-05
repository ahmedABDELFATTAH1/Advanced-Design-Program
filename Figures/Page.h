//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_PAGE_H
#define UNTITLED2_PAGE_H
#include"../common.h"
#include<vector>
class Page {
private:
    std::vector<sf::Shape *> shapes;
    sf::RectangleShape * background;
    sf::RenderWindow* window;
public:
Page(sf::RenderWindow* window,const int upperBarheight);
void drawUI();
void addShape(sf::Shape* shape);
~Page();
};


#endif //UNTITLED2_PAGE_H
