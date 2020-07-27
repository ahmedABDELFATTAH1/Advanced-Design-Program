//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_PLACEHOLDER_H
#define UNTITLED2_PLACEHOLDER_H
#include"../common.h"
#include"Figure.h"
#include"Rectangle.h"
#include<vector>
class PlaceHolder {
private:
    Figure* figure;
    point p1;
    point p2;
    sf::Font* text_font;
    sf::Texture* texure;
    color_comp color;
    std::vector<sf::Text> labels;
public:
PlaceHolder(sf::Font&,point p1,point p2,sf::Texture* tex,color_comp col);
void changeFigure();
void buildUI();
void drawUI(sf::RenderWindow& window);
void addText(sf::Text text)
{
    labels.push_back(text);
}

};


#endif //UNTITLED2_PLACEHOLDER_H
