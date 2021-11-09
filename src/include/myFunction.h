#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <bits/stdc++.h>
using namespace std;

class myFunction
{
private:
    int n;
    int startVal;
    // static int r[10];
    struct stack
    {
        int data[10];
    };
    stack value;

public:
    myFunction();
    ~myFunction();

    void print();
    void pushVal(int);
    void popVal();
    int *container();

protected:
};

#endif MY_FUNCTION