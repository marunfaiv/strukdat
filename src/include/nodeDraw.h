#ifndef NODEDRAW_H
#define NODEDRAW_H

#include "myFunction.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
// using namespace sf;
using namespace std;
#define max_menu 3
class nodeDraw
{
private:
    myFunction *func;
    int x, y;
    int selectedItemIndex;

    sf::Text txtLabel, menu[max_menu];
    sf::Font font;
    sf::Event event;
    sf::RenderWindow *window;

    void setWindow();
    void drawLine(sf::RenderWindow *window, int, int, int, int);
    void drawCircle(sf::RenderWindow *window, int, int, string);
    // void inputHandler(sf::RenderWindow *window);
    void init();

protected:
    // durung enek isine bos, sik bingung wkkw
public:
    nodeDraw(myFunction *func);
    ~nodeDraw();

    void nodesVisual(sf::RenderWindow *window);
    void drawMenu(sf::RenderWindow *window);
    void mainMenu(int, int);
    void moveUp();
    void moveDown();
    int getPressedItem() { return selectedItemIndex; }
};
#endif NODEDRAW_H