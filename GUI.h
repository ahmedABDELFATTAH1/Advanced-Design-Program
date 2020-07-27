//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_GUI_H
#define UNTITLED2_GUI_H

#include <unordered_map>
#include"common.h"
#include "Figures/PlaceHolder.h"

class GUI {
private:
std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>* pages;
sf::RenderWindow* window;
const std::string mainPage="Page";
int numPages;
sf::Font* BLKCHCRY;
void drawPagesLabels();
public:
GUI(std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>*,sf::RenderWindow&);
void draw();
void addPage();
};


#endif //UNTITLED2_GUI_H
