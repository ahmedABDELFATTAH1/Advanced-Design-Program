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
#define GlobalScreenWidth 1366
#define GlobalScreenheight 720

int main()
{
    sf::Clock clock;
    float lastTime = 0;
    sf::RenderWindow window(sf::VideoMode(GlobalScreenWidth, GlobalScreenheight), "Paint For Kids");
    Application application(window);
    window.setKeyRepeatEnabled(false);
    while(window.isOpen())
    {
        clock.restart();
      window.clear();
      application.update();
      application.draw();
      window.display();
      auto hello=clock.getElapsedTime();
    }


}
