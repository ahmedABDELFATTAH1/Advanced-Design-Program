//
// Created by ahmed on ١٨‏/٧‏/٢٠٢٠.
//

#include "Figure.h"
Figure::Figure(color_comp col,point p1,point p2,bool Filled){
this->color=col;
this->p1=p1;
this->p2=p2;
this->needUpdate= true;
isFilled=Filled;
}