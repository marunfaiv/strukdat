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
        {
            data.print();
            // return 0;
        }
        else if (input == 2)
        {
            data.pushData();
            // return 0;
        }
        else if (input == 3)
        {
            data.popData();
            // return 0;
        }
        else if (input == 4)
        {
            data.searchIndexKota();
            // return 0;
        }
        else if (input == 5)
        {
            data.connect();
            // return 0;
        }
        else if (input == 6)
        {
            data.dijkstra();
            // return 0;
        }
        else if (input == 7)
        {
            node.visualCLI();
            // return 0;
        }
        else if (input == 8)
            data.trialError();
    }
    return 0;
}

// garis_hubung[j].setSize(Vector2f(Database->pitagoras((float)x_offset + Database->kota[i].x, (float)y_offset - Database->kota[i].y, (float)x_offset + Database->kota[Database->kota[i].hubungan_kota[temp_j]].x, (float)y_offset - Database->kota[Database->kota[i].hubungan_kota[temp_j]].y), 5));