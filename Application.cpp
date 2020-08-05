
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
    addLeftBar();
    addUpperBar();
    addPage();
}

void Application::draw() {
   Page* p=(*pages)[activePage];
   p->drawUI(*window);
    drawPagesLabels();
}

void Application::addPage() {
    sf::RectangleShape* backGround=new sf::RectangleShape();
    backGround->setPosition({float (window->getSize().x/6),float(upperBarHeight)});
    backGround->setSize({window->getSize().x-float (window->getSize().x/6),float(window->getSize().y-upperBarHeight)});
    backGround->setFillColor({255,255,255});
    Page* p=new Page(backGround);
    (*pages)[buildString+std::to_string(numPages)]=p;
    activePage=buildString+std::to_string(numPages);
    addPageButton();
    activePage=buildString+std::to_string(numPages);
    numPages++;
}

void Application::drawPagesLabels() {
    mod_pages["LEFT_PANEL_BACK"]->drawButton(window);
    for(int i=0;i<panel_vec.size();i++)
    {
        panel_vec[i]->drawButton(window);
    }
    mod_pages["PLUS"]->drawButton(window);
    mod_pages["DELETE"]->drawButton(window);
    mod_pages["PAGES"]->drawButton(window);
    mod_pages["UB_BACKGROUND"]->drawButton(window);
    mod_pages["RECTANGLE"]->drawButton(window);
    mod_pages["TRIANGLE"]->drawButton(window);
}

void Application::setPanel() {
    int positionX=0,positionY=200;
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

void Application::addLeftBar() {

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
    button=new Button(rec,text,"DELETE");
    mod_pages["DELETE"]=button;

    text=new Text();
    positionY += 50;
    positionX=0;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)itemWidth,(float)itemHeight});
    text->setText({int(rec->getPosition().x),int(rec->getPosition().y)},sf::Color::Red,fonts["BLKCHCRY"],std::string("PAGES"));
    button=new Button(rec,text,"PAGES");
    mod_pages["PAGES"]=button;



    text= nullptr;
    positionY = upperBarHeight;
    positionX= 0;
    width=window->getSize().x/6;
    int height=window->getSize().y-upperBarHeight;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)height});
    rec->setOutlineThickness(3);
    rec->setOutlineColor({0,0,0});
    button=new Button(rec,text,"LEFT_PANEL_BACK");
    rec->setFillColor({255,255,255});
    mod_pages["LEFT_PANEL_BACK"]=button;

}

void Application::loadTexture() {
sf::Texture* texture=new sf::Texture;
texture->loadFromFile("assets/plus.png");
textureGroup["PLUS"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/delete.png");
textureGroup["DELETE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/rectangle.png");
textureGroup["RECTANGLE"]=texture;


texture=new sf::Texture;
texture->loadFromFile("assets/triangle.png");
textureGroup["TRIANGLE"]=texture;
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
    } else if(mod_pages["RECTANGLE"]->oNSelected({int(x),int(y)}))
{
    std::cout<<"RECTANGLE"<<std::endl;
}
else if(mod_pages["TRIANGLE"]->oNSelected({int(x),int(y)}))
{
    std::cout<<"TRIANGLE"<<std::endl;
}

}

void Application::mouseReleased(float x, float y) {





}

void Application::addUpperBar() {

    int positionX=0,positionY=0;
    int width=window->getSize().x;
    int height=upperBarHeight;
    Text* text= nullptr;
    sf::RectangleShape * rec=new sf::RectangleShape;
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)height});
    rec->setOutlineThickness(3);
    rec->setOutlineColor({0,0,0});
    Button* button=new Button(rec,text,"UB_BACKGROUND");
    rec->setFillColor({255,255,255});
    mod_pages["UB_BACKGROUND"]=button;

    width=50;
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["RECTANGLE"]);
    button=new Button(rec,text,"RECTANGLE");
    mod_pages["RECTANGLE"]=button;


    positionX+=width;
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["TRIANGLE"]);
    button=new Button(rec,text,"TRIANGLE");
    mod_pages["TRIANGLE"]=button;

}


