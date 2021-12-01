#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <bits/stdc++.h>
#include "nodeDraw.h"
using namespace std;
#define max 10

class myFunction
{
private:
    nodeDraw *node;
    sf::RenderWindow *window;
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
            int jarakKota;
            int idxKota;
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

    int indexSearch(string);
    int minDistance(int dist[], bool sptSet[]);

    string cityNameSearch(int);

    void append(string, int, int /*, int*/);
    void printShortestPath(int[], int, int[], int);
    // void dijkstraGraph();
    void printHubungan(int[], int);

public:
    myFunction(nodeDraw *node);
    ~myFunction();

    // void temp();
    void print();
    void pushData();
    void popData();
    void searchIndexKota();
    void connect();
    void enque();
    void deque();
    void dijkstra();

    // void shortestPath();
    void trialError(sf::RenderWindow *window);

protected:
};

#endif MY_FUNCTION