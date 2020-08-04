
#include "Application.h"
Application::Application(sf::RenderWindow& wind) {
    pages=new  std::unordered_map<std::string,Page*>();
    itemWidth=200;
    itemHeight=50;
    this->pages=pages;
    this->window=&wind;
    numPages=1;
    loadTexture();
    loadFonts();
    addPlusButton();
    addPage();
}

void Application::draw() {
   Page* p=(*pages)[activePage];
   p->drawUI(*window);
   p->drawUI(*window);
    drawPagesLabels();
}

void Application::addPage() {
    sf::RectangleShape* backGround=new sf::RectangleShape();
    backGround->setPosition({0,100});
    backGround->setSize({200,500});
    backGround->setFillColor({255,255,255});
    sf::RectangleShape* elementsLis=new sf::RectangleShape();
    elementsLis->setPosition({200,100});
    elementsLis->setSize({1100,500});
    elementsLis->setFillColor({150,0,0});
    Page* p=new Page(backGround);
    (*pages)[buildString+std::to_string(numPages)]=p;
    activePage=buildString+std::to_string(numPages);
    addPageButton();
    activePage=buildString+std::to_string(numPages);
    numPages++;
}

void Application::drawPagesLabels() {
    for(int i=0;i<panel_vec.size();i++)
    {
        panel_vec[i]->drawButton(window);
    }
    mod_pages["PLUS"]->drawButton(window);
    mod_pages["DELETE"]->drawButton(window);
}

void Application::setPanel() {
    int positionX=0,positionY=150;
    for(int i=0;i<panel_vec.size();i++)
    {
        Button* button=panel_vec[i];
        button->changePosition({positionX,positionY});
        positionY+=itemHeight;
    }
}
void Application::addPageButton()
{
    Text* text=new Text;
    sf::RectangleShape* rec=new sf::RectangleShape();
    rec->setSize({(float)itemWidth,(float)itemHeight});
    rec->setFillColor({100,100,100});
    text->setText({int(rec->getPosition().x),int(rec->getPosition().y)},sf::Color::Red,fonts["BLKCHCRY"],buildString+std::to_string(numPages));
    Button* button=new Button(rec,text,buildString+std::to_string(numPages));
    panel_vec.push_back(button);
    setPanel();
}


void Application::update() {
    while (window->pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::EventType::Closed:
                window->close();
                break;
            case sf::Event::EventType::MouseButtonPressed:
                mousePressed(event.mouseButton.x,event.mouseButton.y);
                break;
            case sf::Event::EventType::MouseButtonReleased:
                break;
            default:
                break;
        }
    }
}

void Application::addPlusButton() {
    int positionX=0,positionY=100;
    int width=50;
    Text* text= nullptr;
    sf::RectangleShape* rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)itemHeight});
    rec->setTexture(textureGroup["PLUS"]);
    Button* button=new Button(rec,text,"PLUS");
    mod_pages["PLUS"]=button;

    positionX+=width;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)itemHeight});
    rec->setTexture(textureGroup["DELETE"]);
    button=new Button(rec,text,"PLUS");
    mod_pages["DELETE"]=button;

}

void Application::loadTexture() {
sf::Texture* texture=new sf::Texture;
texture->loadFromFile("assets/plus.png");
textureGroup["PLUS"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/delete.png");
textureGroup["DELETE"]=texture;
}

void Application::loadFonts() {
    auto* BLKCHCRY=new sf::Font;
    if(!BLKCHCRY->loadFromFile("fonts/BLKCHCRY.TTF"))
        throw ("can't load form this file sorry");
    fonts["BLKCHCRY"]=BLKCHCRY;
}

void Application::mousePressed(float x, float y) {

    for(int i=0;i<panel_vec.size();i++)
    {
        if(panel_vec[i]->oNSelected({int(x),int(y)}))
        {
            panel_vec[i]->changeSelectedUI();
            for(int j=0;j<panel_vec.size();j++)
            {
                if(j!=i&&panel_vec[j]->isSelected())
                {
                    panel_vec[j]->toggleSelected();
                    panel_vec[j]->changeSelectedUI();
                }

            }
        }
        else{
            panel_vec[i]->changeSelectedUI();
        }

    }

if(mod_pages["DELETE"]->oNSelected({int(x),int(y)}))
{
    for(int i=0;i<panel_vec.size();i++)
    {
      if(panel_vec[i]->isSelected())
      {
          std::vector<Button*>::iterator button=panel_vec.begin();
          for(int j=0;j<i;j++)
          {
              button++;
          }
          delete panel_vec[i];
          panel_vec.erase(button);
      }

    }
    setPanel();
    mod_pages["DELETE"]->toggleSelected();

} else if(mod_pages["PLUS"]->oNSelected({int(x),int(y)}))
    {
        addPage();
        mod_pages["PLUS"]->toggleSelected();
        mod_pages["PLUS"]->changeSelectedUI();
    }

}

void Application::mouseReleased(float x, float y) {





}


