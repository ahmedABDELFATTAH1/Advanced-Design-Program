//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#include "Text.h"



Text::Text() {

}

Text::~Text() {

}

void Text::drawText(sf::RenderWindow *window) {
    window->draw(textui);
}

void Text::setText(point pos, sf::Color col, sf::Font* font, std::string str) {
    textui.setString(str);
    textui.setPosition({static_cast<float>(pos.x), static_cast<float>(pos.y)});
    textui.setFont(*font);
    textui.setFillColor(col);
}

void Text::changePosition(point p) {
    textui.setPosition(p.x,p.y);
}
