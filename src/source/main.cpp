#include <bits/stdc++.h>
#include "../include/myFunction.h"
using namespace std;

int main()
{
    myFunction data;

    int input, val;
    while (true)
    {
        cout << "0. Exit\n1. Print\n2. Push\n3. Pop\n4. Search\n5. Connect\n6. Queue\n7. Dequeue" << endl;
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
            data.enque();
        else if (input == 7)
            data.deque();
    }
    return 0;
}