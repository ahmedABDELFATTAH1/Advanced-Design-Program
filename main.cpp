#include <SFML/Graphics.hpp>
#include<vector>
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Line.h"
#include<iostream>
#include<cmath>
#include <utility>
#include"Figures/PlaceHolder.h"
#include<memory>
#include<unordered_map>
#include"GUI.h"
using namespace sf;
int GlobalScreenWidth=1300;
int GlobalScreenheight=600;
int main()
{
    std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>* pages=new std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>();
    sf::RenderWindow window(sf::VideoMode(GlobalScreenWidth, GlobalScreenheight), "Paint For Kids");
    window.setFramerateLimit(60);
    GUI gui(pages,window);
    gui.addPage();
    while(window.isOpen())
    {
      window.clear();
      gui.draw();
      window.display();

    }


}
