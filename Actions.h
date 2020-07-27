//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#ifndef UNTITLED2_ACTIONS_H
#define UNTITLED2_ACTIONS_H
#include<unordered_map>
#include"common.h"
#include"Figures/Figure.h"
class Actions {
private:
std::unordered_map<std::string,std::vector<Figure>*>* worldFigures;
point cursor_location;
public:
Actions(std::unordered_map<std::string,std::vector<Figure>*>* worldfig);
void doAction(point p);


};


#endif //UNTITLED2_ACTIONS_H
