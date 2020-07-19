#include <SFML/Graphics.hpp>
#include<vector>
#include "Figures/Circle.h"
#include "Figures/Rectangle.h"
#include "Figures/Line.h"
#include<iostream>
#define SCREEN_WIDTH 1300
#define SCREEN_HIGH 600
int Figure::numFigures=0;


void uploadAssets(std::vector<Figure*>& assets)
{
    int postionX=3;
    int postionY=3;
    const int width=30;
    const int high=30;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
        {
            assets.emplace_back(new Rectangle({122,0,0},{postionX,postionY},{postionX+width,postionY+high}));
            postionX+=width+3;
        }
        postionX=3;
        postionY=postionY+33;
    }
}
int main()
{

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGH), "Paint For Kids");
    std::vector<Figure*> shapes;
    std::vector<Figure*> assets;
    uploadAssets(assets);
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
                figure=new Circle({0,0,0},p1,p2);
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