//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_PAGE_H
#define UNTITLED2_PAGE_H
#include"../common.h"
#include<vector>
class Page {
private:
    sf::RectangleShape* backGround;
public:
Page(sf::RectangleShape*);
void changeFigure();
void buildUI();
sf::RectangleShape* get_backGround();
void drawUI(sf::RenderWindow& window);
void addText(sf::Text text);
};


#endif //UNTITLED2_PAGE_H
