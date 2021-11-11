#include "nodeDraw.h"

nodeDraw::nodeDraw()
{
    // this->func = func;
}

nodeDraw::~nodeDraw()
{
    delete this;
}

void nodeDraw::drawLine(int x, int y)
{
    this->x = x;
    this->y = y;
    Vertex line[2];
    line[0].position = Vector2f(x, y);
    line[0].color = Color::Yellow;
}