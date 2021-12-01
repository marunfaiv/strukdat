#include "nodeDraw.h"

nodeDraw::nodeDraw()
{
    // this->func = func;
    this->window = window;
    setWindow(window);
    // font.loadFromFile("Arial.ttf");
    // txt.setFont(font);
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

void nodeDraw::drawCircle(sf::RenderWindow *window, int x, int y)
{
    this->x = x;
    this->y = y;
    sf::CircleShape circle(60, 30);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::White);
    circle.getOutlineColor();

    // txt.setString(namaKota);
    // txt.setFillColor(sf::Color::Red);
    // txt.setStyle(sf::Text::Bold);
    // txt.setPosition(sf::Vector2f(100, 300));
    // circle.setOutlineColor(sf::Color::Blue);
    // window->draw(txt);
    window->draw(circle);
}

void nodeDraw::nodesVisual(sf::RenderWindow *window)
{
    drawCircle(window, 100, 200);
    drawCircle(window, 200, 300);
}