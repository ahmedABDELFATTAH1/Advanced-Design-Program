
#include "Application.h"
Application::Application(sf::RenderWindow& wind) {
    APPLICATION_STATE=MOUSE;
    temp= nullptr;
    this->window=&wind;
    itemWidth=window->getSize().x/6;
    itemHeight=50;
    numPages=1;
    loadTexture();
    loadFonts();
    addLeftBar();
    addUpperBar();
    addPage();
    loadSprites();
    programElements["CURSOR"]->toggleSelected();
    programElements["CURSOR"]->changeSelectedTexture();
}
void Application::draw() {
   Page* p=pages[activePage];
   p->drawUI();
   drawPagesLabels();
}
void Application::addPage() {
    Page* p=new Page(window,upperBarHeight);
    pages[buildString+std::to_string(numPages)]=p;
    activePage=buildString+std::to_string(numPages);
    addPageButton();
    numPages++;
}
void Application::drawPagesLabels() {
    programElements["LEFT_PANEL_BACK"]->drawButton(window);
    for(int i=0; i < pagesButtons.size(); i++)
    {
        pagesButtons[i]->drawButton(window);
    }
    programElements["PLUS"]->drawButton(window);
    programElements["DELETE"]->drawButton(window);
    programElements["PAGES"]->drawButton(window);
    programElements["UB_BACKGROUND"]->drawButton(window);
    programElements["RECTANGLE"]->drawButton(window);
    programElements["TRIANGLE"]->drawButton(window);
    programElements["CIRCLE"]->drawButton(window);
    programElements["CURSOR"]->drawButton(window);
    programElements["HAND"]->drawButton(window);
    programElements["LINE"]->drawButton(window);
    window->draw(*cursorImage);
    if(temp)
    window->draw(*temp);
}
void Application::setPanel() {
    int positionX=0,positionY=155;
    for(int i=0; i < pagesButtons.size(); i++)
    {
        Element* button=pagesButtons[i];
        button->changePosition({positionX,positionY});
        positionY+=itemHeight;
    }
}
void Application::addPageButton()
{
    Text* text=new Text;
    sf::RectangleShape* rec=new sf::RectangleShape();
    rec->setSize({(float)itemWidth,(float)itemHeight});
    rec->setFillColor({255,255,255});
    rec->setOutlineColor({20,20,20});
    rec->setOutlineThickness(2);
    text->setText({int(rec->getPosition().x),int(rec->getPosition().y)},sf::Color::Red,fonts["BLKCHCRY"],buildString+std::to_string(numPages));
    Element* button=new Element(rec, text, buildString + std::to_string(numPages));
    pagesButtons.push_back(button);
    setPanel();
}
void Application::update() {
    cursorImage->setPosition(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);
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
                mouseReleased(event.mouseMove.x,event.mouseMove.y);
                break;
            default:
                mouseHighlight(event.mouseMove.x,event.mouseMove.y);
                break;
        }
    }

}
void Application::addLeftBar() {

    int positionX=0,positionY=upperBarHeight;
    int width=50;
    Text* text= nullptr;
    sf::RectangleShape* rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)itemHeight});
    rec->setTexture(textureGroup["PLUS"]);
    Element* button=new Element(rec, text, "PLUS");
    programElements["PLUS"]=button;

    positionX+=width;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)itemHeight});
    rec->setTexture(textureGroup["DELETE"]);
    button=new Element(rec, text, "DELETE");
    programElements["DELETE"]=button;

    text=new Text();
    positionY += 50;
    positionX=0;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)itemWidth,(float)itemHeight});
    text->setText({int(rec->getPosition().x),int(rec->getPosition().y)},sf::Color::Red,fonts["BLKCHCRY"],std::string("PAGES"));
    button=new Element(rec, text, "PAGES");
    programElements["PAGES"]=button;



    text= nullptr;
    positionY = upperBarHeight;
    positionX= 0;
    width=window->getSize().x/6;
    int height=window->getSize().y-upperBarHeight;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)itemWidth,(float)height});
    rec->setOutlineThickness(3);
    rec->setOutlineColor({0,0,0});
    button=new Element(rec, text, "LEFT_PANEL_BACK");
    rec->setFillColor({255,255,255});
    programElements["LEFT_PANEL_BACK"]=button;

}
void Application::loadTexture() {
sf::Texture* texture=new sf::Texture;
texture->loadFromFile("assets/plus.png");
textureGroup["PLUS"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/delete.png");
textureGroup["DELETE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/dot.png");
textureGroup["DOT"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/rectangle.png");
textureGroup["RECTANGLE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/rectangle_selected.png");
textureGroup["RECTANGLE_SELECTED"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/triangle.png");
textureGroup["TRIANGLE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/triangle_selected.png");
textureGroup["TRIANGLE_SELECTED"]=texture;


texture=new sf::Texture;
texture->loadFromFile("assets/circle.png");
textureGroup["CIRCLE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/circle_selected.png");
textureGroup["CIRCLE_SELECTED"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/line.png");
textureGroup["LINE"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/line_selected.png");
textureGroup["LINE_SELECTED"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/hand.png");
textureGroup["HAND"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/hand_selected.png");
textureGroup["HAND_SELECTED"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/resize_diagonal.png");
textureGroup["RESIZE_DIAGONAL"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/resize_horizontal.png");
textureGroup["RESIZE_HORIZONTAL"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/resize_vertical.png");
textureGroup["RESIZE_VERTICAL"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/cursor.png");
textureGroup["CURSOR"]=texture;

texture=new sf::Texture;
texture->loadFromFile("assets/cursor_selected.png");
textureGroup["CURSOR_SELECTED"]=texture;


}
void Application::loadFonts() {
    auto* BLKCHCRY=new sf::Font;
    if(!BLKCHCRY->loadFromFile("fonts/BLKCHCRY.TTF"))
        throw ("can't load form this file sorry");
    fonts["BLKCHCRY"]=BLKCHCRY;
}
void Application::mousePressed(float x, float y) {

    for(int i=0; i < pagesButtons.size(); i++)
    {
        if(pagesButtons[i]->oNSelected({int(x), int(y)}))
        {
            pagesButtons[i]->toggleSelected();
            pagesButtons[i]->changeSelectedUI();
            activePage=pagesButtons[i]->getName();
            for(int j=0; j < pagesButtons.size(); j++)
            {
                if(j!=i && pagesButtons[j]->isSelected())
                {
                    pagesButtons[j]->toggleSelected();
                    pagesButtons[j]->changeSelectedUI();
                }

            }
            break;
        }

    }
    if(APPLICATION_STATE==RESIZE_VERTICAL)
    {
        std::cout<<"RESIZE_VERTICAL"<<std::endl;
      APPLICATION_STATE=RESIZE_VERTICAL;
    }
    else if(APPLICATION_STATE==RESIZE_HORIZONTAL)
    {
        std::cout<<"RESIZE_HORIZONTAL"<<std::endl;
        APPLICATION_STATE=RESIZE_HORIZONTAL;
    }
    else if(onPageBound(x,y))
    {
        switch (APPLICATION_STATE) {
            case MOUSE:
                return;
            case HAND:
            {
                if(pages[activePage]->setSelectedShape(x,y))
                {
                    auto* shape=pages[activePage]->getSelectedShape();


                }

            }
            case SELECT_RECTANGLE:
                temp=new sf::RectangleShape();
                temp->setPosition({x,y});
                temp->setOutlineColor({0,0,0});
                temp->setOutlineThickness(5);
                break;
            case SELECT_CIRCLE:
                temp=new sf::CircleShape();
                temp->setPosition({x,y});
                temp->setOutlineColor({0,0,0});
                temp->setOutlineThickness(5);
                static_cast<sf::CircleShape*>(temp)->setPointCount(200);
                break;
            case SELECT_TRIANGLE:
                temp=new sf::CircleShape();
                temp->setPosition({x,y});
                temp->setOutlineColor({0,0,0});
                temp->setOutlineThickness(5);
                static_cast<sf::CircleShape*>(temp)->setPointCount(3);
                break;
            case SELECT_LINE:
                temp=new sf::RectangleShape();
                temp->setPosition({x,y});
                temp->setFillColor({0,0,0});
                break;
            default:
                break;
        }
    }
else if(programElements["DELETE"]->oNSelected({int(x), int(y)}))
{
    if(pagesButtons.size() == 1)
    {
        std::cout<<"Only one Page can't delete it sorry "<<std::endl;
        return;
    }
    for(int i=0; i < pagesButtons.size(); i++)
    {
      if(pagesButtons[i]->isSelected())
      {
          pagesButtons[i]->toggleSelected();
          std::vector<Element*>::iterator button=pagesButtons.begin();
          for(int j=0;j<i;j++)
          {
              button++;
          }
          delete pagesButtons[i];
          pagesButtons.erase(button);
          delete  pages[activePage];
          pages.erase(activePage);
          activePage =pagesButtons[0]->getName();
      }

    }
    setPanel();

} else if(programElements["PLUS"]->oNSelected({int(x), int(y)}))
    {
        addPage();
    }
else if(programElements["RECTANGLE"]->oNSelected({int(x), int(y)}))
{

    for(int i=0;i<actionButtons.size();i++)
    {
        if(actionButtons[i]->isSelected())
        {
            actionButtons[i]->toggleSelected();
            actionButtons[i]->changeSelectedTexture();
        }
    }
    programElements["RECTANGLE"]->toggleSelected();
    programElements["RECTANGLE"]->changeSelectedTexture();
    APPLICATION_STATE=SELECT_RECTANGLE;

}
else if(programElements["TRIANGLE"]->oNSelected({int(x), int(y)}))
{

    for(int i=0;i<actionButtons.size();i++)
    {
        if(actionButtons[i]->isSelected())
        {
            actionButtons[i]->toggleSelected();
            actionButtons[i]->changeSelectedTexture();
        }
    }
    programElements["TRIANGLE"]->toggleSelected();
    programElements["TRIANGLE"]->changeSelectedTexture();
    APPLICATION_STATE=SELECT_TRIANGLE;
}

else if(programElements["CIRCLE"]->oNSelected({int(x), int(y)}))
{

    for(int i=0;i<actionButtons.size();i++)
    {
        if(actionButtons[i]->isSelected())
        {
            actionButtons[i]->toggleSelected();
            actionButtons[i]->changeSelectedTexture();
        }
    }
    programElements["CIRCLE"]->toggleSelected();
    programElements["CIRCLE"]->changeSelectedTexture();
    APPLICATION_STATE=SELECT_CIRCLE;
}
    else if(programElements["LINE"]->oNSelected({int(x), int(y)}))
    {

        for(int i=0;i<actionButtons.size();i++)
        {
            if(actionButtons[i]->isSelected())
            {
                actionButtons[i]->toggleSelected();
                actionButtons[i]->changeSelectedTexture();
            }
        }
        programElements["LINE"]->toggleSelected();
        programElements["LINE"]->changeSelectedTexture();
        APPLICATION_STATE=SELECT_LINE;
    }
else if(programElements["CURSOR"]->oNSelected({int(x), int(y)})) {
        for(int i=0;i<actionButtons.size();i++)
        {
            if(actionButtons[i]->isSelected())
            {
                actionButtons[i]->toggleSelected();
                actionButtons[i]->changeSelectedTexture();
            }
        }
        programElements["CURSOR"]->toggleSelected();
        programElements["CURSOR"]->changeSelectedTexture();
        APPLICATION_STATE=MOUSE;
    }
else if(programElements["HAND"]->oNSelected({int(x), int(y)}))
{
    for(int i=0;i<actionButtons.size();i++)
    {
        if(actionButtons[i]->isSelected())
        {
            actionButtons[i]->toggleSelected();
            actionButtons[i]->changeSelectedTexture();
        }
    }
    programElements["HAND"]->toggleSelected();
    programElements["HAND"]->changeSelectedTexture();
    APPLICATION_STATE=HAND;
}

}
void Application::mouseReleased(float x, float y) {
    if (temp) {
    switch (APPLICATION_STATE) {
            case MOUSE:
                return;
            case SELECT_RECTANGLE:
            pages[activePage]->addShape(temp);
            temp= nullptr;
            break;
            case SELECT_CIRCLE:
            pages[activePage]->addShape(temp);
            temp= nullptr;
            break;
            case SELECT_TRIANGLE:
            pages[activePage]->addShape(temp);
            temp= nullptr;
            break;
            case SELECT_LINE:
            pages[activePage]->addShape(temp);
            temp= nullptr;
            break;
            default:
                break;
        }
    }


}
void Application::moveUpperBar() {



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
    Element* button=new Element(rec, text, "UB_BACKGROUND");
    rec->setFillColor({255,255,255});
    programElements["UB_BACKGROUND"]=button;

    width=50;
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["RECTANGLE"]);
    button=new Element(rec, text, "RECTANGLE");
    button->setTextures(textureGroup["RECTANGLE_SELECTED"]);
    programElements["RECTANGLE"]=button;
    actionButtons.push_back(button);

    positionX+=(width+20);
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["TRIANGLE"]);
    button=new Element(rec, text, "TRIANGLE");
    button->setTextures(textureGroup["TRIANGLE_SELECTED"]);
    programElements["TRIANGLE"]=button;
    actionButtons.push_back(button);

    positionX+=(width+20);
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["CIRCLE"]);
    button=new Element(rec, text, "CIRCLE");
    button->setTextures(textureGroup["CIRCLE_SELECTED"]);
    programElements["CIRCLE"]=button;
    actionButtons.push_back(button);


    positionX+=(width+20);
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["LINE"]);
    button=new Element(rec, text, "LINE");
    button->setTextures(textureGroup["LINE_SELECTED"]);
    programElements["LINE"]=button;
    actionButtons.push_back(button);


    positionX+=(width+20);
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["CURSOR"]);
    button=new Element(rec, text, "CURSOR");
    button->setTextures(textureGroup["CURSOR_SELECTED"]);
    programElements["CURSOR"]=button;
    actionButtons.push_back(button);

    positionX+=(width+20);
    text= nullptr;
    rec=new sf::RectangleShape();
    rec->setPosition(positionX,positionY);
    rec->setSize({(float)width,(float)upperBarHeight});
    rec->setTexture(textureGroup["HAND"]);
    button=new Element(rec, text, "HAND");
    button->setTextures(textureGroup["HAND_SELECTED"]);
    programElements["HAND"]=button;
    actionButtons.push_back(button);
}
void Application::mouseHighlight(float x, float y) {
if(programElements["CURSOR"]->isSelected()) {
    if (x > itemWidth - 10 && x < itemWidth + 10 && y > upperBarHeight + 10)//this means resize horizontaly
    {
        APPLICATION_STATE = RESIZE_HORIZONTAL;
        cursorImage->setTexture(textureGroup["RESIZE_HORIZONTAL"]);

    } else if (y > upperBarHeight - 10 && y < upperBarHeight + 10 && x > itemWidth) {
        APPLICATION_STATE = RESIZE_VERTICAL;
        cursorImage->setTexture(textureGroup["RESIZE_VERTICAL"]);
    } else {
        APPLICATION_STATE = MOUSE;
        cursorImage->setTexture(textureGroup["CURSOR"]);
    }

}
else if( x < itemWidth || y < upperBarHeight)
{
    cursorImage->setTexture(textureGroup["CURSOR"]);

}
else if(programElements["RECTANGLE"]->isSelected()||programElements["CIRCLE"]->isSelected()||programElements["TRIANGLE"]->isSelected()
||programElements["LINE"]->isSelected()){
    cursorImage->setTexture(textureGroup["DOT"]);
}
else if(programElements["HAND"]->isSelected())
{
    cursorImage->setTexture(textureGroup["HAND"]);
}
if(temp) {
    if(x<itemWidth)
        x=itemWidth+5;
    if(y<upperBarHeight)
        y=upperBarHeight+5;
    switch (APPLICATION_STATE) {
        case MOUSE:
            return;
        case SELECT_RECTANGLE: {
            auto *rec = static_cast<sf::RectangleShape *>(temp);
            rec->setSize({x - rec->getPosition().x, y - rec->getPosition().y});
            break;
        }
        case SELECT_CIRCLE: {
            std::cout<<"HELLO";
            auto *circle = static_cast<sf::CircleShape *>(temp);
            float radius=sqrt(pow(x-circle->getPosition().x,2)+pow(y-circle->getPosition().y,2));
            circle->setRadius(radius);
            break;
        }
        case SELECT_TRIANGLE: {
            auto *tri = static_cast<sf::CircleShape *>(temp);
            float radius = sqrt(pow(x - tri->getPosition().x, 2) + pow(y - tri->getPosition().y, 2));
            tri->setRadius(radius);
            break;
        }
        case SELECT_LINE: {
            auto *rec = static_cast<sf::RectangleShape *>(temp);
            float angle=atan2(y-rec->getPosition().y,x-rec->getPosition().x);
            rec->setSize({float(sqrt(pow(x-rec->getPosition().x,2)+pow(y-rec->getPosition().y,2))), 5});
            rec->setRotation(angle*180/M_PI);
            break;
        }
        default:
            break;
    }
}
}
void Application::loadSprites() {
    cursorImage=new sf::RectangleShape();
    cursorImage->setSize({40,40});
    cursorImage->setTexture(textureGroup["CURSOR"]);
    window->setMouseCursorVisible(false);
}
bool Application::onPageBound(int x, int y) {
    if(x>itemWidth && y>upperBarHeight)
    {
        return true;
    }
        return false;
}



