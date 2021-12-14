#include "nodeDraw.h"
nodeDraw::nodeDraw(myFunction *func)
{
    this->func = func;
    init();
}

nodeDraw::~nodeDraw()
{
    delete this;
}

void nodeDraw::init()
{
    // this->func = func;
    // func->print();
    this->event = event;

    setWindow();

    tambah_kota = 0;
    flag = 0;
    flag2 = 0;
    // listKota[100] = {
    //     "A",
    //     "B",
    //     "C",
    //     "D",
    //     "E",
    //     "F",
    //     "G",
    //     "H",
    //     "I",
    //     "J",
    //     "K",
    //     "L",
    // };

    isSelected = false;
    hasLimit = false;
    isClicked = false;

    main_cursor.loadFromSystem(sf::Cursor::Arrow);

    font.loadFromFile("/home/arya/tugas/struktur-data/src/include/Arial.ttf");
    txtLabel.setFont(font);
    authorName.setFont(font);
    txtQ.setFont(font);
    txtBox.setFont(font);
    // txtOutput1.setFont(font);
    // txtOutput2.setFont(font);
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

void nodeDraw::drawAppend(string nama, int x, int y)
{
    data[tambah_kota].namaKota = nama;
    data[tambah_kota].x = x;
    data[tambah_kota].y = y;
    tambah_kota++;
}

void nodeDraw::mainMenu(int width, int height)
{
    // Author e bos
    authorName.setString("CREATED BY ARYA ABDUL AZIS");
    authorName.setPosition(sf::Vector2f((width / 2) - 230, (height / height) - 1));

    // Pilihan menu e
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
    menu[2].setString("MANUAL DRAW");
    menu[2].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 4));

    // menu[3].setFont(font);
    // menu[3].setFillColor(sf::Color::White);
    // menu[3].setString("Exit");
    // menu[3].setPosition(sf::Vector2f((width / 2) - 150, height / (max_menu + 1) * 4));
    selectedItemIndex = 0;
}

void nodeDraw::drawMenu(sf::RenderWindow *window)
{
    for (int i = 0; i < max_menu; i++)
        window->draw(menu[i]);
    window->draw(authorName);
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

    string nama;
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
        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!flag)
            {
                // tambah_kota++;
                flag = 1;
            }
            // cout << tambah_kota << endl;
            isClicked = true;
            flag2 = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isClicked = false;
            if (flag)
                flag = 0;
        }

        // Munculin gambar
        if (isClicked)
        {
            // tambah_kota++;
            mouse_coordinate = sf::Mouse::getPosition(*window);
            // Buat Gambar
            // drawCircle(window, mouse_coordinate[tambah_kota].x, mouse_coordinate[tambah_kota].y, nama);
            // cout << "AAAAA\n";
            // update(mouse_coordinate.x, mouse_coordinate.y);
        }
        else if (!isClicked)
        {
            if (flag2)
            {
                cout << "Masukkan Nama Kota: ";
                cin >> nama;
                // func->append(nama, mouse_coordinate.x, mouse_coordinate.y);
                // cout << nama << endl;
                func->append(nama, mouse_coordinate.x, mouse_coordinate.y);
                // drawAppend(nama, mouse_coordinate.x, mouse_coordinate.y);
                // cout << "X: " << data[tambah_kota].x << "\n";
                // cout << "Y: " << data[tambah_kota].y << "\n";
                // cout << "Nama: " << data[tambah_kota].namaKota << endl;
                flag2 = false;
            }
            // continue;
        }

        for (int i = 0; i < func->listData.top; i++)
        {
            drawCircle(window, func->listData.dataKota[i].x, func->listData.dataKota[i].y, func->listData.dataKota[i].namaKota);
            for (int j = 0; j < func->listData.top; j++)
            {
                if (func->checkHubungan(func->listData.dataKota[i].namaKota, func->listData.dataKota[j].namaKota) == true)
                {
                    drawLine(window, func->listData.dataKota[i].x, func->listData.dataKota[i].y, func->listData.dataKota[j].x, func->listData.dataKota[j].y);
                }
            }
        }

        window->display();
    }
}

void nodeDraw::shortestPathVisual(sf::RenderWindow *window)
{
    txtQ.setString("Pilih Kota: ");
    txtQ.setPosition(sf::Vector2f(0, 0));
    // txtOutput1.setPosition(sf::Vector2f(150, 0));
    // txtOutput2.setPosition(sf::Vector2f(200, 0));

    textBox(30, sf::Color::White, true);
    setPosition(sf::Vector2f(150, 0)); // set Pos text
    while (window->isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            setSelected(false);
            getString();
        }
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        //     setSelected(false);
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::TextEntered:
                typeOn(event);
                break;
            }
        }
        window->clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }
        window->draw(txtQ);
        drawText(window);
        window->display();
    }
}

void nodeDraw::manualDraw(sf::RenderWindow *window)
{
    // // sf::String namaKota;
    string nama;
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
        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!flag)
            {
                // tambah_kota++;
                flag = 1;
            }
            // cout << tambah_kota << endl;
            isClicked = true;
            flag2 = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isClicked = false;
            if (flag)
                flag = 0;
        }

        // Munculin gambar
        if (isClicked)
        {
            // tambah_kota++;
            mouse_coordinate = sf::Mouse::getPosition(*window);
            // Buat Gambar
            // drawCircle(window, mouse_coordinate[tambah_kota].x, mouse_coordinate[tambah_kota].y, nama);
            // cout << "AAAAA\n";
            // update(mouse_coordinate.x, mouse_coordinate.y);
        }
        else if (!isClicked)
        {
            if (flag2)
            {
                cout << "Masukkan Nama Kota: ";
                cin >> nama;
                // func->append(nama, mouse_coordinate.x, mouse_coordinate.y);
                // cout << nama << endl;
                drawAppend(nama, mouse_coordinate.x, mouse_coordinate.y);
                // cout << "X: " << data[tambah_kota].x << "\n";
                // cout << "Y: " << data[tambah_kota].y << "\n";
                // cout << "Nama: " << data[tambah_kota].namaKota << endl;
                flag2 = false;
                // func->append(nama, mouse_coordinate->x, mouse_coordinate->y);
            }
            // continue;
        }

        for (int i = 0; i < tambah_kota; i++)
        {
            drawCircle(window, data[i].x, data[i].y, data[i].namaKota);
            // for (int j = 0; j < func->listData.top; j++)
            // {
            //     if (func->checkHubungan(func->listData.dataKota[i].namaKota, func->listData.dataKota[j].namaKota) == true)
            //     {
            //         drawLine(window, func->listData.dataKota[i].x, func->listData.dataKota[i].y, func->listData.dataKota[j].x, func->listData.dataKota[j].y);
            //     }
            // }
        }

        window->display();
    }
}

// void nodeDraw::update(int x, int y)
// {
//     // this->window = window;
//     sf::RenderWindow *updateWindow;
//     xmouse[100] = x;
//     ymouse[100] = y;
//     drawCircle(updateWindow, xmouse[0], ymouse[0], "A");
// }

void nodeDraw::textBox(int size, sf::Color color, bool sel)
{
    txtBox.setCharacterSize(size);
    txtBox.setColor(color);
    // txtBox.setPosition(sf::Vector2f(x, y));
    isSelected = sel;

    if (sel)
    {
        txtBox.setString("_");
    }
    else
    {
        txtBox.setString("");
    }
}

void nodeDraw::deleteLogic()
{
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    text.str("");
    text << newT;

    txtBox.setString(text.str());
}

void nodeDraw::inputLogic(int charTyped)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    else if (charTyped == DELETE_KEY)
    {
        if (text.str().length() > 0)
        {
            deleteLogic();
        }
    }
    txtBox.setString(text.str() + "_");
}

void nodeDraw::setSelected(bool sel)
{
    isSelected = sel;
    if (!sel)
    {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        txtBox.setString(newT);
    }
}

void nodeDraw::setPosition(sf::Vector2f pos)
{
    txtBox.setPosition(pos);
}

void nodeDraw::typeOn(sf::Event input)
{
    if (isSelected)
    {
        int charTyped = input.text.unicode;
        if (charTyped < 128)
        {
            if (hasLimit)
            {
                if (text.str().length() <= limit)
                    inputLogic(charTyped);
                else if (text.str().length() > limit && charTyped == DELETE_KEY)
                    deleteLogic();
            }
            else
                inputLogic(charTyped);
        }
    }
}

// fungsi alokasi
void nodeDraw::drawText(sf::RenderWindow *window)
{
    window->draw(txtBox);
}

// void nodeDraw::getX(int x)
// {
//     this->x[banyak_kota] = x;
// }

// void nodeDraw::getY(int y)
// {
//     this->y[banyak_kota] = y;
// }

// void nodeDraw::getName(string name)
// {
//     this->nama[banyak_kota] = name;
// }

// void nodeDraw::getTotKota(int total)
// {
//     this->banyak_kota = total;
// }

// void nodeDraw::dataPointer(myFunction *func)
// {
//     this->func = func;
// }