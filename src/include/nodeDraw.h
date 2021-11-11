#ifndef NODEDRAW_H
#define NODEDRAW_H

// #include "myFunction.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class nodeDraw
{
private:
    // myFunction *func;
    int x, y;

protected:
    // durung enek isine bos, sik bingung wkkw
public:
    nodeDraw();
    ~nodeDraw();
    void drawLine(int, int);
    void drawCircle(string);
};
#endif NODEDRAW_H