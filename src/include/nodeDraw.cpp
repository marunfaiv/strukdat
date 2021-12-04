#include "nodeDraw.h"

nodeDraw::nodeDraw(myFunction *func)
{
    // this->func = func;
    init();
}

nodeDraw::~nodeDraw()
{
    delete this;
}

void nodeDraw::init()
{
    // this->func = func;
    this->event = event;
    setWindow();
    font.loadFromFile("/home/arya/tugas/struktur-data/src/include/Arial.ttf");
    txtLabel.setFont(font);
}

void nodeDraw::setWindow()
{
    this->window = window;
}

void nodeDraw::drawLine(sf::RenderWindow *window, int x1, int y1, int x2, int y2)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2)),
        // sf::Vertex(sf::Color::Yellow),
        // line->color.Yellow;
    };
    line->color = sf::Color::Yellow;
    window->draw(line, 2, sf::Lines);
}

void nodeDraw::drawCircle(sf::RenderWindow *window, int x, int y, string txt)
{
    this->x = x;
    this->y = y;
    sf::CircleShape circle(30, 15);
    circle.setPosition(x - 25, y - 25);
    circle.setFillColor(sf::Color::White);
    circle.getOutlineColor();

    // std::stringstream txtLabel;
    // txtLabel << txt;
    txtLabel.setString(txt);
    if (txt == "A" or txt == "B")
        txtLabel.setPosition(sf::Vector2f(x - 10, y - 65));
    else if (txt == "C" or txt == "D")
        txtLabel.setPosition(sf::Vector2f(x - 10, y + 20));
    else
        txtLabel.setPosition(sf::Vector2f(x - 5, y + 20));
    txtLabel.setFillColor(sf::Color::Red);
    txtLabel.setStyle(sf::Text::Bold);
    txtLabel.setCharacterSize(40);
    // circle.setOutlineColor(sf::Color::Blue);

    window->draw(circle);
    window->draw(txtLabel);
}

void nodeDraw::mainMenu(int width, int height)
{
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Yellow);
    menu[0].setString("SHOW MAP");
    menu[0].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("FIND SHORTEST PATH");
    menu[1].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 3));

    selectedItemIndex = 0;
}

void nodeDraw::drawMenu(sf::RenderWindow *window)
{
    for (int i = 0; i < max_menu; i++)
        window->draw(menu[i]);
}

void nodeDraw::moveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

void nodeDraw::moveDown()
{
    if (selectedItemIndex + 1 < max_menu)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}

void nodeDraw::nodesVisual(sf::RenderWindow *window)
{
    // Anggap saja ini screen x dan y aku bagi /10 semuaz
    int abLine, acLine, bdLine, cdLine, beLine, deLine;
    int xA, yA, xB, yB, xC, yC, xD, yD, xE, yE;
    this->txtLabel = txtLabel;
    xA = 360, yA = 180;
    xB = 720, yB = 180;
    xC = 360, yC = 420;
    xD = 720, yD = 420;
    xE = 960, yE = 300;

    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            }
        }
        window->clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return;
        // Lingkaran
        drawCircle(window, xA, yA, "A");
        drawCircle(window, xB, yB, "B");
        drawCircle(window, xC, yC, "C");
        drawCircle(window, xD, yD, "D");
        drawCircle(window, xE, yE, "E");
        // Garis
        drawLine(window, xA, yA, xB, yB); // A ke B
        drawLine(window, xA, yA, xC, yC); // A ke C
        drawLine(window, xB, yB, xD, yD); // B ke D
        drawLine(window, xB, yB, xE, yE); // B ke E
        drawLine(window, xC, yC, xD, yD); // C ke D
        drawLine(window, xD, yD, xE, yE); // D ke E

        window->display();
    }
    // window->draw(txtLabel);
}