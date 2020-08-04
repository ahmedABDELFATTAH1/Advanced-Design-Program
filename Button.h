//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_BUTTON_H
#define UNTITLED2_BUTTON_H

#include"common.h"
#include"Figures/Text.h"
class Button {
private:
    sf::RectangleShape* rectangle;
    Text* text;
    std::string buttonName;
    bool selected;
    int temp=0;
public:
    Button(sf::RectangleShape* rec,Text* tex,std::string btn_name);
    bool isSelected();
    void toggleSelected();
    bool oNSelected(point p);//should change the UI and the underlaying state
    void drawButton(sf::RenderWindow* window);
    void changeSelectedUI();
    void changePosition(point p);
    ~Button();

};


#endif //UNTITLED2_BUTTON_H
