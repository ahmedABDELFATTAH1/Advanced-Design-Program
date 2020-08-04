//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_APPLICATION_H
#define UNTITLED2_APPLICATION_H

#include <unordered_map>
#include"common.h"
#include "Figures/Page.h"
#include"Button.h"
class Application {
private:
    std::unordered_map<std::string,Page*>* pages;
    std::unordered_map<std::string,Button*> mod_pages;
    std::unordered_map<std::string,sf::Texture*> textureGroup;
    std::unordered_map<std::string,sf::Font*> fonts;
    std::string activePage;
    const std::string buildString="Page";
    sf::Event event;
    int itemWidth;
    int itemHeight;
    std::vector<Button*> panel_vec;
    sf::RenderWindow* window;
    int numPages;
    void addPlusButton();
    void loadTexture();
    void loadFonts();
    void mousePressed(float x,float y);
    void mouseReleased(float x,float y);
    void addPage();
    void setPanel();
    void drawPagesLabels();
    void addPageButton();
public:
    Application(sf::RenderWindow&);
    void draw();
    void update();
};

#endif //UNTITLED2_APPLICATION_H
