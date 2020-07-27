//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "PlaceHolder.h"

PlaceHolder::PlaceHolder(sf::Font& f,point p1,point p2,sf::Texture* tex,color_comp col): text_font(&f),p1(p1),p2(p2),
texure(tex),color(col)
{
    figure=new Rectangle(col,p1,p2, true, nullptr);
}

void PlaceHolder::changeFigure() {

}

void PlaceHolder::buildUI() {

}

void PlaceHolder::drawUI(sf::RenderWindow& window) {

window.draw(figure->getUI());
for(auto text:labels)
{
    window.draw(text);
}
}
