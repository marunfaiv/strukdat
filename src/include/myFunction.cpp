#include "myFunction.h"

myFunction::myFunction()
{
    n = 5;
    startVal = -1;
}

myFunction::~myFunction()
{
}

void myFunction::print()
{
    // int *val;

    // val = container();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << *(val + i) << " ";
    // }
    // cout << "\n";
    if (startVal == -1)
    {
        cout << "Still no data..\n";
        return;
    }
    cout << "Data: ";
    for (int i = 0; i <= startVal; i++)
    {
        cout << value.data[i] << " ";
    }
    cout << "\n";
}

void myFunction::pushVal(int input)
{
    startVal += 1;
    value.data[startVal] = input;
    if (startVal == 9)
    {
        cout << "Cannot enter more data..\n";
    }
}

void myFunction::popVal()
{
    // value.data[startVal] = 0;
    if (startVal == -1)
    {
        cout << "No data to erase..\n";
    }
    else
    {
        startVal -= 1;
    }
    // return value.data[startVal];
}

int *myFunction::container()
{
    static int arr[100];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        // cout << arr[i] << endl;
    }

    return arr;
}
