#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <bits/stdc++.h>
using namespace std;
#define max 10

class myFunction
{
private:
    // int n;
    // int startVal;
    // // static int r[10];
    // struct stack
    // {
    //     int data[10];
    // };
    // stack value;
    struct stack
    {
        int top;
        struct kota
        {
            string namaKota;
            string hubKota[max];
            int x, y;
            int nextNode[max];
            int lastNode;
        } dataKota[max];
    } listData;

    struct que
    {
        int depan;
        int belakang;
        struct qKota
        {
            string namaKota;
            int x;
            int y;
        } qData[max];
    } q;
    bool isFull();
    bool isEmpty();
    bool qFull();
    bool qEmpty();
    void append(string, int, int);
    int indexSearch(string);

public:
    myFunction();
    ~myFunction();

    void print();
    void pushData();
    void popData();
    void searchIndexKota();
    void connect();
    void enque();
    void deque();

protected:
};

#endif MY_FUNCTION