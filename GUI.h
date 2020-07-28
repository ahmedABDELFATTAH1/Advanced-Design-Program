//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_GUI_H
#define UNTITLED2_GUI_H

#include <unordered_map>
#include"common.h"
#include "Figures/PlaceHolder.h"
#include"Button.h"
class GUI {
private:
    std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>* pages;
    sf::RenderWindow* window;
    std::string activePage;
    const std::string buildString="Page";
    int numPages;
    sf::Font* BLKCHCRY;
    std::vector<Button*> panel_vec;
    void drawPagesLabels();
    int itr;
    sf::Event event;
    int state;
    std::unordered_map<std::string,Button*> mod_pages;
    void addPanelButton(Button button);
    std::unordered_map<std::string,sf::Texture> textureGroup;
    void addPlusButton();
    void loadTexture();
public:
    GUI(std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>*,sf::RenderWindow&);
    void draw();
    void addPage();
    void setPanel();
    void update();
};
enum clickStates{
    NORMAL,PRESSED_Trigger,Pressing
};


#endif //UNTITLED2_GUI_H
