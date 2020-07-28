//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_TEXT_H
#define UNTITLED2_TEXT_H
#include "../common.h"

class Text {
private:
    sf::Text textui;
public:
    void drawText(sf::RenderWindow * window);
    void setText(point pos,sf::Color col,sf::Font*,std::string str);
    Text();
    ~Text();
};


#endif //UNTITLED2_TEXT_H
