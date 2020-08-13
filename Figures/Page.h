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
    sf::Shape* selectedShape;
    color_comp selectedColor;
public:
Page(sf::RenderWindow* window,const int upperBarheight);
void drawUI();
void addShape(sf::Shape* shape);
bool setSelectedShape(int x,int y);
sf::Shape* getSelectedShape();
void deleteSelectedShape();
void unSelect();
void moveSelectedShape(int x, int y);
~Page();
};


#endif //UNTITLED2_PAGE_H
