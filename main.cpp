#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include<cmath>
#include <utility>
#include"Figures/Page.h"
#include<memory>
#include<unordered_map>
#include"Application.h"
using namespace sf;
int GlobalScreenWidth=1300;
int GlobalScreenheight=600;
int main()
{
    sf::RenderWindow window(sf::VideoMode(GlobalScreenWidth, GlobalScreenheight), "Paint For Kids");
    Application application(window);
    window.setKeyRepeatEnabled(false);
    while(window.isOpen())
    {
      window.clear();
      application.update();
      application.draw();
      window.display();

    }


}
