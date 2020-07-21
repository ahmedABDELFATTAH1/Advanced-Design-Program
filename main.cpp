#include <SFML/Graphics.hpp>
#include<vector>
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Line.h"
#include<iostream>
#define SCREEN_WIDTH 1300
#define SCREEN_HIGH 600
#include<cmath>
int Figure::numFigures=0;
color_comp GlobalColor;
void uploadAssets(std::vector<Figure*>& assets)
{
    int postionX=0;
    int postionY=0;
    constexpr int width=5;
    const int high=30;
    constexpr float intervals=SCREEN_WIDTH/(float(width)*4);
    float added=ceil(256/intervals);
    while(postionX<SCREEN_WIDTH)
    {
        assets.emplace_back(new Rectangle(GlobalColor,{postionX,postionY},{postionX+width,postionY+high}, true));
        postionX+=width;
        GlobalColor.r+=added;
        if(GlobalColor.r>=254)
            break;
    }
    postionX=0;
    postionY=30;
    GlobalColor={0,0,0};
    while(postionX<SCREEN_WIDTH)
    {
        assets.emplace_back(new Rectangle(GlobalColor,{postionX,postionY},{postionX+width,postionY+high}, true));
        postionX+=width;
        GlobalColor.g+=added;
        if(GlobalColor.g>=254)
            break;
    }
    postionX=0;
    postionY=60;
    GlobalColor={0,0,0};
    while(postionX<SCREEN_WIDTH)
    {
        assets.emplace_back(new Rectangle(GlobalColor,{postionX,postionY},{postionX+width,postionY+high}, true));
        postionX+=width;
        GlobalColor.b+=added;
        if(GlobalColor.b>=254)
            break;
    }
}

int main()
{
    GlobalColor={0,0,0};
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGH), "Paint For Kids");
    std::vector<Figure*> shapes;
    std::vector<Figure*> assets;
  // uploadAssets(assets);
   sf::Texture texture;
   if(!texture.loadFromFile("assets/grid.png"))
    {
        std::cout<<"Load Failed"<<std::endl;
        system("pause");
    }

   sf::Sprite sprite;
   sprite.setTexture(texture);
   float scaleFactorx=SCREEN_WIDTH/texture.getSize().x;
   float scaleFactory=SCREEN_WIDTH/texture.getSize().y;
   sprite.scale(scaleFactorx,scaleFactory);
    bool makeShape= false;
    Figure* figure= nullptr;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type==sf::Event::MouseButtonPressed || makeShape)
            {

                sf::Vector2i position;
                position=sf::Mouse::getPosition(window);
                point p1;
                point p2;
                if(!makeShape)
                {
                    p1=position;
                }
                p2=position;
                delete figure;
                figure=new Circle({0,0,0},p1,p2, false);
                figure->printDimentions();
                makeShape= true;
            }

            if(event.type==sf::Event::MouseButtonReleased)
            {
                shapes.emplace_back(figure);

                figure= nullptr;
                makeShape= false;

            }


        }

        window.clear({255,255,255});
        window.draw(sprite);
        if(figure)
        {
            window.draw(figure->getUI());
        }

        for(Figure* shape : shapes)
        {
            window.draw(shape->getUI());
        }
        for(Figure* shape : assets)
        {
            window.draw(shape->getUI());
        }

        window.display();
    }

    return 0;
}