#include "nodeDraw.h"

nodeDraw::nodeDraw()
{
    init();
}

nodeDraw::~nodeDraw()
{
    delete this;
}

void nodeDraw::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void nodeDraw::drawLineUp(sf::RenderWindow *window)
{
    sf::Vertex line[] = {
        // line->position(10,300),
        sf::Vertex(sf::Vector2f(100, 350)),
        sf::Vertex(sf::Vector2f(300, 200))};
    window->draw(line, 2, sf::Lines);
}

void nodeDraw::drawLineDown(sf::RenderWindow *window)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(100, 350)),
        sf::Vertex(sf::Vector2f(300, 500))};
    window->draw(line, 2, sf::Lines);
}

void nodeDraw::drawCircle(sf::RenderWindow *window, int x, int y, string txt)
{
    this->x = x;
    this->y = y;
    sf::CircleShape circle(60, 30);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::White);
    circle.getOutlineColor();

    // std::stringstream txtLabel;
    // txtLabel << txt;
    txtLabel.setString(txt);
    txtLabel.setFillColor(sf::Color::Red);
    txtLabel.setStyle(sf::Text::Bold);
    txtLabel.setPosition(sf::Vector2f(x+45, y+30));
    txtLabel.setCharacterSize(50);
    circle.setOutlineColor(sf::Color::Blue);

    // while (true)
    // {
        
    // }
    
    window->draw(circle);
    window->draw(txtLabel);
}

void nodeDraw::init()
{
    // this->func = func;
    this->window = window;
    this->event = event;
    setWindow(window);
    font.loadFromFile("/home/arya/tugas/struktur-data/src/include/Arial.ttf");
    txtLabel.setFont(font);
    // while (true)
    // {
        // while (window->pollEvent(event))
        // {

        //     switch (event.type)
        //     {

        //     case sf::Event::Closed:
        //         window->close();
        //         break;
        //     }
        // }

        // window->clear();

        // // highscore.str("");
        // // highscore << "HIGH SCORE : " << *score;
        // // highscorelbl.setString(highscore.str());

        // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        // {
        //     return window->close();
        // }

        // window->draw(text);
        // window->draw(text2);
        // window->draw(highscorelbl);

        // window->display();
    // }
}

void nodeDraw::nodesVisual(sf::RenderWindow *window)
{
    // drawCircle(window, x, y, "A");
}