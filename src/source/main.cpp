#include <bits/stdc++.h>
#include "../include/myFunction.h"
#include "../include/nodeDraw.h"
using namespace std;

int main(int argc, char **argv)
{
    myFunction data;
    nodeDraw node(&data);
    // node.dataPointer(&data);
    // printf("main: %x\n", &data);
    // MainAwal:
    int input;
    while (true)
    {
        cout << "\n0. Exit\n1. Print\n2. Push\n3. Pop\n4. Search\n5. Connect\n6. Cari Jalur\n7. Visual"
             << endl;
        cout << "Pilihanmu adalah: ";
        cin >> input;
        if (input == 0)
            break;
        else if (input == 1)
            data.print();
        else if (input == 2)
            data.pushData();
        else if (input == 3)
            data.popData();
        else if (input == 4)
            data.searchIndexKota();
        else if (input == 5)
            data.connect();
        else if (input == 6)
            data.dijkstra();
        else if (input == 7)
        {
            // int chc;
            // cout << "1. Show Map Visual\n2. Show Dijkstra Visual\n";
            // cout << "Pilihanmu: ";
            // cin >> chc;
            // if(chc == 1)
            //     node.nodesVisual();
            // else if(chc == 2)
            //     node.shortestPathVisual();
            sf::RenderWindow window(sf::VideoMode(1200, 600), "Map GUI");
            sf::Event event;
            // sf::Vector2i mouse_coordinate;
            // sf::Cursor main_cur;
            // main_cur.loadFromSystem(sf::Cursor::Arrow);
            // window.setMouseCursor(main_cur);
            node.mainMenu(window.getSize().x, window.getSize().y);
            // node.selectedItemIndex = 0;
            while (window.isOpen())
            {
                // mouse_coordinate = sf::Mouse::getPosition(window);
                // printf("%d %d\n", mouse_coordinate.x, mouse_coordinate.y);
                // cout << "Terserahhhahaha\n";
                while (window.pollEvent(event))
                {
                    switch (event.type)
                    {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::KeyReleased:
                        switch (event.key.code)
                        {
                        case sf::Keyboard::Up:
                            node.moveUp();
                            break;
                        case sf::Keyboard::Down:
                            node.moveDown();
                            break;
                        case sf::Keyboard::Enter:
                            switch (node.getPressedItem())
                            {
                            case 0:
                                node.nodesVisual(&window);
                                // goto MainAwal;
                                break;
                            case 1:
                                node.shortestPathVisual(&window);
                                // goto MainAwal;
                                break;
                            case 2:
                                node.manualDraw(&window);
                                // goto MainAwal;
                                break;
                            case 3:
                                // node.selectedItemIndex = -1;
                                // cout << "TERSERAH\n";
                                window.close();
                                break;
                            }
                        }
                    }
                }
                // cout << "EVENT TYPE: ";
                // cout << event.type << endl;
                // cout << "EVENT KEY: ";
                // cout << event.key.code << "\n";
                // cout << "GET PRESSED: ";
                // cout << node.getPressedItem() << endl;
                window.clear();
                node.drawMenu(&window);
                window.display();
            }
        }
        else if (input == 8)
            data.trialError();
    }
    return 0;
}

// garis_hubung[j].setSize(Vector2f(Database->pitagoras((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y), 5));