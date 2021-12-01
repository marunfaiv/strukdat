#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <bits/stdc++.h>
#include "nodeDraw.h"
using namespace std;
#define max 9

class myFunction : public nodeDraw
{
private:
    nodeDraw *node;
    sf::RenderWindow *window;
    // struct hubKota
    // {
    //     string kotaTujuan;
    //     int jarak;
    // };
    // struct hubKota hub;
    struct stack
    {
        int top;
        struct kota
        {
            string namaKota;
            // string hubKota[max];
            int x, y;
            int nextNode[max];
            // vector<struct hubKota> nextKota;
            int lastNode;
            int jarakKota;
            int idxKota;
            struct hubKota
            {
                int jarak;
                string tujuanKota;
            } hub[max];
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
    void connectKota(string, string, int);

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
    void hubunganKota();
    void jarakKota();
    // void shortestPath();
    void trialError();

protected:
};

#endif MY_FUNCTION