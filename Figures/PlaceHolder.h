//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_PLACEHOLDER_H
#define UNTITLED2_PLACEHOLDER_H
#include"../common.h"
#include<vector>
class PlaceHolder {
private:
    sf::RectangleShape* backGround;
    std::vector<sf::Text> labels;
public:
PlaceHolder(sf::RectangleShape*);
void changeFigure();
void buildUI();
sf::RectangleShape* get_backGround();
void drawUI(sf::RenderWindow& window);
void addText(sf::Text text)
{
    labels.push_back(text);
}

};


#endif //UNTITLED2_PLACEHOLDER_H
