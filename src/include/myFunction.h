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
    int iter = 0;
    int src, dst;
    string nama[batas];
    int jarak[batas];
    bool isTraveled[batas] = {0};
    int parent[batas];
    int graph[batas][batas];
    int pathCheck[batas][batas];
    // int iter_dijkstra;
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

    // vector<vector<float>> distanceData;

    bool isFull();
    bool isEmpty();
    bool qFull();
    bool qEmpty();

    int minDistance(int dist[], bool sptSet[]);

    string cityNameSearch(int);

    // void dijkstraGraph();
    void printHubungan(int[], int);
    void printAllPath(int[], int, int[], int);
    void printSinglePath(int[], int, int[], int, int);
    void dataJarak(int);
    void initDijkstra();

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
                int idxTujuanKota;
            } hub[batas];
        } dataKota[batas];
    } listData;

    // string listHubungan[batas];
    // int dataDijkstra[batas];
    vector<int> dataDijkstra;

    bool checkHubungan(string, string);
    bool isPath(int, int);
    int kotaTerdekat(string);
    int indexSearch(string);

    float distanceMaker(int, int, int, int);

    void append(string, int, int);
    void connectKota(string, string);
    void print();
    void pushData();
    void popData();
    void searchIndexKota();
    void connect();
    void multipleConnection();
    void enque();
    void deque();
    void dijkstra();
    void hubunganKota();
    void trialError();

protected:
};

#endif MY_FUNCTION

// if (sudah_dilewati[dst_temp] == 0 && data_jarak_kota[src_temp][dst_temp] > 0 && jarak_antar_node[src_temp] + data_jarak_kota[src_temp][dst_temp] < jarak_antar_node[dst_temp])
//         {
//             // printf("seng masok: %d dan %d ->  %d dan %d \n", src_temp, dst_temp, jarak_antar_node[src_temp], jarak_antar_node[dst_temp]);
//             path_temp[dst_temp] = src_temp;
//             jarak_antar_node[dst_temp] = jarak_antar_node[src_temp] + data_jarak_kota[src_temp][dst_temp];
//             // printf("sak marine diproses %d\n", jarak_antar_node[dst_temp]);
//         }