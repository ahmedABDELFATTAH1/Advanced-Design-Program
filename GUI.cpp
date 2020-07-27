//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "GUI.h"
GUI::GUI(std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>* pages,sf::RenderWindow& wind) {
this->pages=pages;
this->window=&wind;
BLKCHCRY=new sf::Font;
numPages=1;
if(!BLKCHCRY->loadFromFile("fonts/BLKCHCRY.TTF"))
    throw ("can't load form this file sorry");
std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(*BLKCHCRY,{0,100},{200,600}, nullptr,{200,200,200}),
                                   new PlaceHolder(*BLKCHCRY,{200,100},{1300,600}, nullptr,{100,100,100}));

(*pages)[mainPage+std::to_string(numPages)]=p;
}

void GUI::draw() {
    std::pair<PlaceHolder*,PlaceHolder*>* p=(*pages)[mainPage+std::to_string(numPages)];
    p->first->drawUI(*window);
    p->second->drawUI(*window);
    drawPagesLabels();
}



void GUI::addPage() {
    std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(*BLKCHCRY,{0,100},{200,600}, nullptr,{200,200,200}),
                                                                                      new PlaceHolder(*BLKCHCRY,{200,100},{1300,600}, nullptr,{100,100,100}));
    numPages++;
    (*pages)[mainPage+std::to_string(numPages)]=p;

}

void GUI::drawPagesLabels() {
    int positionX=10,positionY=150;
    sf::Text text;
    text.setFillColor(sf::Color::Red);
    text.setFont(*BLKCHCRY);
    text.setCharacterSize(20);
    for(int i=0;i<numPages;i++)
    {
        text.setPosition({static_cast<float >(positionX), static_cast<float >(positionY)});
        positionY+=50;
        text.setString(mainPage+std::to_string(i));
        window->draw(text);
    }


}

