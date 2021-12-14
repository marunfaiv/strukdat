#ifndef MYFUNCTION_H
#define MYFUNCTION_H

#include <bits/stdc++.h>
// #include "nodeDraw.h"
using namespace std;
// #define max 9
#define batas 100

class myFunction
{
private:
    // const int max = 9;
    int x[batas], y[batas];
    string nama[batas];
    // nodeDraw *node;
    // sf::RenderWindow *window;d
    // struct hubKota
    // {
    //     string kotaTujuan;
    //     int jarak;
    // };
    // struct hubKota hub;

    struct que
    {
        int depan;
        int belakang;
        struct qKota
        {
            string namaKota;
            int x;
            int y;
        } qData[9];
    } q;

    bool isFull();
    bool isEmpty();
    bool qFull();
    bool qEmpty();

    int indexSearch(string);
    int minDistance(int dist[], bool sptSet[]);

    float distanceMaker(int, int, int, int);

    string cityNameSearch(int);

    // void dijkstraGraph();
    void printHubungan(int[], int);
    void connectKota(string, string);
    void printAllPath(int[], int, int[], int);
    void printSinglePath(int[], int, int[], int, int);

public:
    myFunction();
    ~myFunction();

    struct stack
    {
        int top;
        struct kota
        {
            string namaKota;
            // string hubKota[max];
            int x, y;
            int nextNode[batas];
            // vector<struct hubKota> nextKota;
            int lastNode;
            int jarakKota;
            int idxKota;
            struct hubKota
            {
                int jarak;
                string tujuanKota;
            } hub[batas];
        } dataKota[batas];
    } listData;

    bool checkHubungan(string, string);

    void append(string, int, int);
    void print();
    void pushData();
    void popData();
    void searchIndexKota();
    void connect();
    void enque();
    void deque();
    void dijkstra();
    void hubunganKota();
    void trialError();

protected:
};

#endif MY_FUNCTION