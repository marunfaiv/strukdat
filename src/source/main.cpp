#include <bits/stdc++.h>
#include "../include/myFunction.h"
using namespace std;

int main()
{
    myFunction func;

    int input, val;
    while (true)
    {
        cout << "0. Exit\n1. Print\n2. PopVal\n3. PushVal\n";
        cin >> input;
        if (input == 0)
            break;
        else if (input == 1)
        {
            func.print();
            cout << "\n";
        }
        else if (input == 2)
        {
            func.popVal();
            cout << "\n";
        }
        else if (input == 3)
        {
            cin >> val;
            func.pushVal(val);
            cout << "\n";
        }
    }
    return 0;
}