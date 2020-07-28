//
// Created by ahmed on ٢٤‏/٧‏/٢٠٢٠.
//

#include "GUI.h"
GUI::GUI(std::unordered_map<std::string,std::pair<PlaceHolder*,PlaceHolder*>*>* pages,sf::RenderWindow& wind) {
    state=NORMAL;
this->pages=pages;
this->window=&wind;
numPages=itr=1;
loadTexture();
BLKCHCRY=new sf::Font;
if(!BLKCHCRY->loadFromFile("fonts/BLKCHCRY.TTF"))
    throw ("can't load form this file sorry");


    sf::RectangleShape* backGround=new sf::RectangleShape();
    backGround->setPosition({0,100});
    backGround->setSize({200,500});
    backGround->setFillColor({255,255,255});
    sf::RectangleShape* elementsLis=new sf::RectangleShape();
    elementsLis->setPosition({200,100});
    elementsLis->setSize({1100,500});
    elementsLis->setFillColor({150,0,0});
    std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(backGround),
                                                                                      new PlaceHolder(elementsLis));

(*pages)[buildString+std::to_string(numPages)]=p;
addPlusButton();
setPanel();
activePage=buildString+std::to_string(numPages);
panel_vec[0]->toggleSelected();
}

void GUI::draw() {
    std::pair<PlaceHolder*,PlaceHolder*>* p=(*pages)[activePage];
    p->first->drawUI(*window);
    p->second->drawUI(*window);
    drawPagesLabels();
}



void GUI::addPage() {
    sf::RectangleShape* backGround=new sf::RectangleShape();
    backGround->setPosition({0,100});
    backGround->setSize({200,500});
    backGround->setFillColor({255,255,255});
    sf::RectangleShape* elementsLis=new sf::RectangleShape();
    elementsLis->setPosition({200,100});
    elementsLis->setSize({1100,500});
    elementsLis->setFillColor({150,0,0});
    std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(backGround),
                                                                                      new PlaceHolder(elementsLis));
    numPages++;
    (*pages)[buildString+std::to_string(numPages)]=p;
    activePage=buildString+std::to_string(numPages);
    setPanel();
}

void GUI::drawPagesLabels() {


    int x=sf::Mouse::getPosition(*window).x;
    int y=sf::Mouse::getPosition(*window).y;
    for(int i=0;i<panel_vec.size();i++)
    {
        if(state==PRESSED_Trigger)
        {
            bool gotSelected=panel_vec[i]->oNSelected({x,y});
            if(gotSelected)
            {
                panel_vec[i]->changeSelectedUI();
            }

        }
        panel_vec[i]->drawButton(window);
    }

    mod_pages["PLUS"]->drawButton(window);
    if(state==PRESSED_Trigger) {
        mod_pages["PLUS"]->oNSelected({x,y});
    }
        if(mod_pages["PLUS"]->isSelected())
    {
        addPage();
        mod_pages["PLUS"]->toggleSelected();
    }

    state=NORMAL;
}

void GUI::setPanel() {
    static int positionX=0,positionY=150;
    int high=50;
    int width=200;
    for(int i=itr;i<=numPages;i++)
    {
        if(numPages>5)
        {
            std::cout<<"HEllo ";
        }
        Text* text=new Text;
        //{255,255,255},{positionX,positionY},{positionX+width,positionY+high},false, nullptr
        sf::RectangleShape* rec=new sf::RectangleShape();
        rec->setPosition(positionX,positionY);
        rec->setSize({(float)width,(float)high});
        text->setText({int(rec->getPosition().x),int(rec->getPosition().y)},sf::Color::Red,BLKCHCRY,buildString+std::to_string(i));
        positionY+=50;
        Button* button=new Button(rec,text,buildString+std::to_string(i));
        panel_vec.push_back(button);
    }
    itr=numPages+1;
}


void GUI::update() {
    while (window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::EventType::Closed:
                window->close();
                break;
            case sf::Event::EventType::MouseButtonPressed:
                state=PRESSED_Trigger;
                break;
            case sf::Event::EventType::MouseButtonReleased:
                break;
            default:
                break;
        }
    }
}

void GUI::addPlusButton() {
    int positionX=0,positionY=100;
    int high=50;
    int width=200;
    Text* text= nullptr;
    sf::RectangleShape* rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)high});
    positionY+=50;
    Button* button=new Button(rec,text,"PLUS");
    mod_pages["PLUS"]=button;
}

void GUI::loadTexture() {
sf::Texture* texture=new sf::Texture;
texture->loadFromFile("assets/plus.png");
textureGroup["PLUS"]=*texture;
}


