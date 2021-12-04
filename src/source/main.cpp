#include <bits/stdc++.h>
#include "../include/myFunction.h"
#include "../include/nodeDraw.h"
using namespace std;

int main(int argc, char **argv)
{
    myFunction data;
    nodeDraw node(&data);
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
            sf::RenderWindow window(sf::VideoMode(1200, 600), "Map GUI");
            sf::Event event;
            node.mainMenu(window.getSize().x, window.getSize().y);
            while (window.isOpen())
            {
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
                        case sf::Keyboard::Return:
                            switch (node.getPressedItem())
                            {
                            case 0:
                                node.nodesVisual(&window);
                                break;
                            case 1:
                                node.nodesVisual(&window);
                                break;
                            case 2:
                                window.close();
                                break;
                            }
                        }
                    }
                }
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