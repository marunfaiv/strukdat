#ifndef NODEDRAW_H
#define NODEDRAW_H
#define max_menu 4
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

#include "myFunction.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;

class nodeDraw : public myFunction
{
private:
    struct dataKota
    {
        string namaKota;
        int x;
        int y;
    } data[100];

    myFunction *func;
    int tambah_kota;
    int xmouse[100], ymouse[100];
    int abLine, acLine, bdLine, cdLine, beLine, deLine;
    int limit;
    ostringstream text;
    bool hasLimit, isSelected, isClicked, flag, flag2;
    vector<int> buffer;

    sf::Text txtLabel, menu[max_menu], authorName, txtBox;
    sf::Text txtQ;
    sf::String txtInput1, txtInput2;
    sf::Font font;
    sf::Event event;
    sf::RenderWindow *window;
    sf::Vector2i mouse_coordinate;
    sf::Cursor main_cursor;
    sf::Touch mouse;
    // sf::Vertex line[] = {
    //     sf::Vertex(sf::Vector2f(x,y)),
    // };

    bool isPath(int,int);

    void setWindow();
    void drawAppend(string, int, int);
    void drawLine(sf::RenderWindow *window, int, int, int, int, sf::Color);
    void drawCircle(sf::RenderWindow *window, int, int, string);
    void init();

    // input text
    void textBox(int, sf::Color, bool);
    void deleteLogic();
    void inputLogic(int);
    void setPosition(sf::Vector2f);
    // void terimaInputText(sf::Text, sf::Text);
    void drawText(sf::RenderWindow *window);
    void setSelected(bool sel);
    void typeOn(sf::Event);

    string getString() { return text.str(); }

protected:
    // durung enek isine bos, sik bingung
public:
    nodeDraw(myFunction *func);
    ~nodeDraw();

    // buat di class nodeDraw
    int selectedItemIndex;

    void visualCLI();
    void shortestPathVisual(bool);
    void nodesVisual();
    void drawMenu(sf::RenderWindow *window);
    void mainMenu(int, int);
    void moveUp();
    void moveDown();
    void manualDraw(sf::RenderWindow *window);
    void update(int, int);

    int getPressedItem() { return selectedItemIndex; }

    // buat diambil value di class sebelah
    void getTotKota(int);
    void getX(int);
    void getY(int);
    void getName(string);
    void dataPointer(myFunction *func);
};

#endif NODEDRAW_H