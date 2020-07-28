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
std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(BLKCHCRY,{0,100},{200,600}, nullptr,{200,200,200}),
                                   new PlaceHolder(BLKCHCRY,{200,100},{1300,600}, nullptr,{100,100,100}));

(*pages)[buildString+std::to_string(numPages)]=p;
addPlusButton();
setPanel();
activePage=buildString+std::to_string(numPages);


}

void GUI::draw() {
    std::pair<PlaceHolder*,PlaceHolder*>* p=(*pages)[activePage];
    p->first->drawUI(*window);
    p->second->drawUI(*window);
    drawPagesLabels();
}



void GUI::addPage() {
    std::pair<PlaceHolder*,PlaceHolder*>* p=new std::pair<PlaceHolder*,PlaceHolder*> (new PlaceHolder(BLKCHCRY,{0,100},{200,600}, nullptr,{200,200,200}),
                                                                                      new PlaceHolder(BLKCHCRY,{200,100},{1300,600}, nullptr,{100,100,100}));
    numPages++;
    (*pages)[buildString+std::to_string(numPages)]=p;
    activePage=buildString+std::to_string(numPages);
    setPanel();
}

void GUI::drawPagesLabels() {

    mod_pages["Plus"]->drawButton(window);
    for(int i=0;i<panel_vec.size();i++)
    {
        if(state==PRESSED_Trigger)
        {
            int x=sf::Mouse::getPosition(*window).x;
            int y=sf::Mouse::getPosition(*window).y;
            bool gotSelected=panel_vec[i]->oNSelected({x,y});
            if(gotSelected)
            {

            }

        }
        panel_vec[i]->drawButton(window);
    }
    state=NORMAL;
    if(mod_pages["Plus"]->isSelected())
    {
        addPage();
        mod_pages["Plus"]->toggleSelected();
    }


}

void GUI::setPanel() {
    static int positionX=0,positionY=150;
    int high=50;
    int width=200;
    for(int i=itr;i<=numPages;i++)
    {
        Text* text=new Text;
        Rectangle* rec=new Rectangle({255,255,255},{positionX,positionY},{positionX+width,positionY+high},false, nullptr);
        text->setText({int(rec->getUI().getPosition().x),int(rec->getUI().getPosition().y)},sf::Color::Red,BLKCHCRY,buildString+std::to_string(i));
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
    Rectangle* rec=new Rectangle({255,255,255},{positionX,positionY},{positionX+width,positionY+high},false,&textureGroup["PLUS"]);
    positionY+=50;
    Button* button=new Button(rec,text,"PLUS");
    panel_vec.push_back(button) ;
    mod_pages["PLUS"]=button;
}

void GUI::loadTexture() {
sf::Texture* texture=new sf::Texture;
texture->loadFromFile("assets/plus.png");
textureGroup["PLUS"]=*texture;
}


