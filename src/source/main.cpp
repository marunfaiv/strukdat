#include <bits/stdc++.h>
#include "../include/myFunction.h"
#include "../include/nodeDraw.h"
using namespace std;

int main(int argc, char **argv)
{
    nodeDraw node;
    myFunction data(&node);
    int input;

    while (true)
    {
        cout << "\n0. Exit\n1. Print\n2. Push\n3. Pop\n4. Search\n5. Connect\n6. Cari Jalur\n7. Visual"
             << endl;
        cin >> input;
        cout << "Pilihanmu adalah: " << input << endl;
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
            while (window.isOpen())
            {
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                // window.setActive();
                window.clear();
                // data.trialError(&window);
                // node.drawLine();
                // node.drawLine(100, 100);
                // window.draw(line, 2, sf::Lines);
                node.nodesVisual(&window);
                window.display();
            }
        }
    }

    return 0;
}