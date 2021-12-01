#ifndef NODEDRAW_H
#define NODEDRAW_H

// #include "myFunction.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
// using namespace sf;
using namespace std;

class nodeDraw
{
private:
    // myFunction *func;
    int x, y;
    sf::Text txtLabel;
    sf::Font font;
    sf::Event event;
    sf::RenderWindow *window;

    void setWindow(sf::RenderWindow *window);
    void drawLineUp(sf::RenderWindow *window);
    void drawLineDown(sf::RenderWindow *window);
    void drawCircle(sf::RenderWindow *window, int, int, string);
    void init();

protected:
    // durung enek isine bos, sik bingung wkkw
public:
    nodeDraw();
    ~nodeDraw();

    void nodesVisual(sf::RenderWindow *window);
};
#endif NODEDRAW_H