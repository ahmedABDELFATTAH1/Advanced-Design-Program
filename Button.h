//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_BUTTON_H
#define UNTITLED2_BUTTON_H

#include"common.h"
#include"Figures/Rectangle.h"
#include"Figures/Text.h"
class Button {
private:
    Rectangle* rectangle;
    Text* text;
    std::string buttonName;
    bool selected;
    int temp=0;
public:
    Button(Rectangle* rec,Text* tex,std::string btn_name);
    bool isSelected();
    void toggleSelected();
    bool oNSelected(point p);//should change the UI and the underlaying state
    void drawButton(sf::RenderWindow* window);
    ~Button();

};


#endif //UNTITLED2_BUTTON_H
