//
// Created by ahmed on ٢٧‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_ELEMENT_H
#define UNTITLED2_ELEMENT_H

#include"common.h"
#include"Figures/Text.h"
class Element {
private:
    sf::RectangleShape* rectangle;
    Text* text;
    Text* SelectedTexture;
    std::string buttonName;
    const sf::Texture* texture1;
    const sf::Texture* texture2;
    bool selected;
    int temp=0;
public:
    Element(sf::RectangleShape* rec, Text* tex, std::string btn_name);
    bool isSelected();
    void toggleSelected();
    bool oNSelected(point p);//should change the UI and the underlaying state
    void drawButton(sf::RenderWindow* window);
    void changeSelectedUI();
    void changePosition(point p);
    void changeSelectedTexture();
    void setTextures(sf::Texture* tex2);
    std::string getName();
    ~Element();

};


#endif //UNTITLED2_ELEMENT_H
