//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_APPLICATION_H
#define UNTITLED2_APPLICATION_H

#include <unordered_map>
#include"common.h"
#include "Figures/Page.h"
#include"Element.h"
#include <random>
enum states{
    MOUSE,SELECT_LINE,SELECT_TRIANGLE,SELECT_CIRCLE,SELECT_RECTANGLE,SELECT_ERASE,HAND,RESIZE_HORIZONTAL,RESIZE_VERTICAL
};
class Application {
private:
    std::unordered_map<std::string,Page*> pages;
    std::unordered_map<std::string,Element*> programElements;
    std::unordered_map<std::string,sf::Texture*> textureGroup;
    std::vector<Element*> actionButtons;
    std::vector<Element*> pagesButtons;
    std::unordered_map<std::string,sf::Font*> fonts;
    sf::RectangleShape* cursorImage;
    int APPLICATION_STATE;
    bool moveItem;
    std::string activePage;
    const std::string buildString="Page";
    sf::Event event;
    int itemWidth;
    int itemHeight;
    int upperBarHeight=50;
    sf::Shape * temp;
    sf::RenderWindow* window;
    int numPages;
    void addLeftBar();
    void loadTexture();
    void loadFonts();
    void mousePressed(float x,float y);
    void mouseReleased(float x,float y);
    void addPage();
    void setPanel();
    void drawPagesLabels();
    void addUpperBar();
    void addPageButton();
    void mouseHighlight(float x,float y);
    void loadSprites();
    bool onPageBound(int x,int y);
    void moveUpperBar();
public:
    Application(sf::RenderWindow&);
    void draw();
    void update();
};

#endif //UNTITLED2_APPLICATION_H
