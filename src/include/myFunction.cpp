#include "myFunction.h"

//Constructor
myFunction::myFunction(nodeDraw *node)
{
    this->node = node;
    this->window = window;
    listData.top = 0;
    // listData.dataKota.lastNode = -1;
    q.belakang = 0;
    q.depan = 0;

    // struct hubKota hub;
    // vector<struct kota> dataKota;

    append("A", 100, 200);
    append("B", 200, 300);
    append("C", 300, 400);
    append("D", 400, 500);
    append("E", 500, 600);

    connectKota("A", "B", 1);
    connectKota("A", "C", 2);
    connectKota("B", "D", 5);
    connectKota("B", "E", 1);
    connectKota("C", "D", 2);
    connectKota("D", "E", 3);
    // node->nodesVisual(window);
}

//Destructor
myFunction::~myFunction()
{
    delete this;
}

//Private Function
void myFunction::append(string nama, int x, int y /*, int jarak*/)
{
    listData.dataKota[listData.top].namaKota = nama;
    listData.dataKota[listData.top].x = x;
    listData.dataKota[listData.top].y = y;
    listData.dataKota[listData.top].lastNode = -1;
    listData.dataKota[listData.top].idxKota = listData.top;
    // listData.dataKota[listData.top].jarakKota = jarak;
    listData.top++;

    // node->(window, x, y, nama);
}

bool myFunction::isFull()
{
    return listData.top == max - 1;
}

bool myFunction::isEmpty()
{
    return listData.top == 0;
}

bool myFunction::qFull()
{
    return q.belakang == max;
}

bool myFunction::qEmpty()
{
    return q.belakang == 0;
}

int myFunction::indexSearch(string nama)
{
    int indx = 0;
    for (int i = listData.top; i >= 0; i--)
    {
        if (listData.dataKota[i].namaKota == nama)
        {
            // cout << "Kota berada pada index ke-" << i << endl;
            indx = i;
        }
    }
    return indx;
}

string myFunction::cityNameSearch(int idx)
{
    string namaKota;
    for (int i = listData.top; i >= 0; i--)
    {
        if (idx == listData.dataKota[i].idxKota)
        {
            namaKota = listData.dataKota[i].namaKota;
        }
    }
    return namaKota;
}

//Public Function
void myFunction::print()
{
    // int chc = 0;
    // cout << "Data dari Push atau Antrian \n1 = Push \n2 = Queue " << endl;
    // cin >> chc;
    cout << "\t\t\tDATA KOTA\n";
    // header
    // cout << "Index Kota:\t";
    cout << "Nama:\t";
    cout << "X:\t";
    cout << "Y:\t";
    cout << "Hubungan:\t";
    cout << "Jarak:\n";
    // if (chc == 1)
    // {
    if (isEmpty())
        cout << "Ga enek sing di print..\n";
    // isi
    for (int i = 0; i < listData.top; i++)
    {
        // cout << listData.dataKota[i].idxKota << "\t\t";
        cout << listData.dataKota[i].namaKota << "\t";
        cout << listData.dataKota[i].x << "\t";
        cout << listData.dataKota[i].y << "\t";
        // cout << listData.dataKota[i].jarakKota << "\t";

        if (listData.dataKota[i].lastNode == -1)
            cout << "- ";
        else
        {
            for (int j = 0; j < listData.dataKota[i].lastNode; j++)
            {
                cout << listData.dataKota[i].hub[j].tujuanKota << ", ";
                // cout << listData.dataKota[i].hub[j].jarak << ", ";
                //cout << listData.dataKota[0].nextKota.front().kotaTujuan; cout <<  hub.kotaTujuan << ", ";
                // cout << listData.dataKota[j].nextKota.front().kotaTujuan << ", ";
            }
            cout << listData.dataKota[i].hub[listData.dataKota[i].lastNode].tujuanKota << "\t\t";

            for (int k = 0; k < listData.dataKota[i].lastNode; k++)
            {
                cout << listData.dataKota[i].hub[k].jarak << ", ";
            }
            cout << listData.dataKota[i].hub[listData.dataKota[i].lastNode].jarak << " ";
        }

        // for (int k = 0; k < listData.dataKota[i].lastNode; k++)
        // {
        //     cout << listData.dataKota[i].hub[k].jarak << ", ";
        // }
        // cout << listData.dataKota[i].hub[listData.dataKota[i].lastNode].jarak << " ";
        cout << endl;
    }
    // }
    // else if (chc == 2)
    // {
    //     if (qEmpty())
    //         cout << "Antrian kosong bosquu...";
    //     // isi
    //     for (int i = q.depan; i < q.belakang; i++)
    //     {
    //         cout << q.qData[i].namaKota << "\t";

    //         cout << q.qData[i].x << "\t";
    //         cout << q.qData[i].y << "\t";
    //         cout << endl;
    //     }
    // }
}

void myFunction::pushData()
{
    string nama;
    int x, y;
    int jarak;
    if (isFull())
        cout << "Wes full bro..." << endl;
    else
    {
        cout << "Masukkan Nama Kota: ";
        cin >> nama;
        cout << "X dan Y: ";
        cin >> x >> y;
        // jarak = (x + y) / 2;
        append(nama, x, y /*, jarak*/);
    }
}

void myFunction::popData()
{
    if (isEmpty())
        cout << "Ga enek Data...\n";
    else
        listData.top--;
}

void myFunction::searchIndexKota()
{
    string nama;
    cout << "Masukkan nama Kota yang ingin dicari: ";
    cin >> nama;
    if (isEmpty())
        cout << "Nothing to search...\n";

    for (int i = listData.top; i >= 0; i--)
    {
        if (listData.dataKota[i].namaKota == nama)
        {
            cout << "Kota berada pada index ke-" << i << endl;
        }
    }
}

void myFunction::connect()
{
    string kota1, kota2;
    cout << "Masukkan nama Kota yang ingin dihubungkan: ";
    cin >> kota1;
    cin >> kota2;

    cout << "Masukkan jarak antar Kota";
    int jarak;
    cin >> jarak;
    int id1 = indexSearch(kota1);
    int id2 = indexSearch(kota2);

    if (id1 >= 0 and id2 >= 0)
    {
        listData.dataKota[id1].lastNode++;
        listData.dataKota[id1].hub[listData.dataKota[id1].lastNode].tujuanKota = kota2;
        listData.dataKota[id1].nextNode[listData.dataKota[id1].lastNode] = id2;
        listData.dataKota[id1].hub[listData.dataKota[id1].lastNode].jarak = jarak;

        /* ini untuk connect 2 arah */
        listData.dataKota[id2].lastNode++;
        listData.dataKota[id2].hub[listData.dataKota[id2].lastNode].tujuanKota = kota1;
        listData.dataKota[id2].nextNode[listData.dataKota[id2].lastNode] = id1;
        listData.dataKota[id2].hub[listData.dataKota[id2].lastNode].jarak = jarak;
    }
    else
        cout << "Kuto ne ra temu bos...\n";
}

void myFunction::connectKota(string kotaAsal, string kotaTujuan, int jarak)
{
    int id1 = indexSearch(kotaAsal);
    int id2 = indexSearch(kotaTujuan);

    if (id1 >= 0 and id2 >= 0)
    {
        listData.dataKota[id1].lastNode++;
        listData.dataKota[id1].hub[listData.dataKota[id1].lastNode].tujuanKota = kotaTujuan;
        listData.dataKota[id1].nextNode[listData.dataKota[id1].lastNode] = id2;
        listData.dataKota[id1].hub[listData.dataKota[id1].lastNode].jarak = jarak;

        /* ini untuk connect 2 arah */
        listData.dataKota[id2].lastNode++;
        listData.dataKota[id2].hub[listData.dataKota[id2].lastNode].tujuanKota = kotaAsal;
        listData.dataKota[id2].nextNode[listData.dataKota[id2].lastNode] = id1;
        listData.dataKota[id2].hub[listData.dataKota[id2].lastNode].jarak = jarak;

        // hub.kotaTujuan = kotaTujuan;
        // hub.jarak = jarak;
        // listData.dataKota[id1].nextKota.push_back(hub);
    }
}

void myFunction::enque()
{
    if (qFull())
        cout << "Antrian Full kaka...\n";
    else
    {
        string nama;
        int x, y;
        cout << "Masukkan nama Kota: ";
        cin >> nama;
        cout << "Masukkan x dan y kota: ";
        cin >> x >> y;
        q.qData[q.belakang].namaKota = nama;
        q.qData[q.belakang].x = x;
        q.qData[q.belakang].y = y;
        q.belakang++;
    }
}

void myFunction::deque()
{
    if (qEmpty())
        cout << "Antri dulu bang...\n";
    else
    {
        for (int i = q.depan; i < q.belakang; i++)
            q.qData[i] = q.qData[i + 1];
        q.belakang--;
    }
}

void myFunction::trialError()
{
    // cout << listData.top << endl;
    // cout << "Hubungan Kota\t\t"
    //      << "Jarak\n";
    // for (int i = 0; i < listData.dataKota->nextKota.size(); i++)
    // {
    //     // cout << listData.dataKota[i].nextKota.front().jarak << endl;
    //     cout << listData.dataKota[i].nextKota.front().kotaTujuan << " ";
    // }

    //     cout << "Masukkan nama kota: ";
    //     string kota;
    //     cin >> kota;

    //     int n = indexSearch(kota);

    //     for (int i = 0; i < listData.dataKota[n].nextKota.size(); i++)
    //     {
    //         cout << listData.dataKota[i].nextKota.front().kotaTujuan << ", ";
    //     }
    cout << listData.dataKota[0].hub[0].tujuanKota << endl;
    cout << listData.dataKota[0].hub[1].tujuanKota << endl;
}

int myFunction::minDistance(int dist[], bool isTraveled[])
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < listData.top; i++)
    {
        if (isTraveled[i] == false and dist[i] <= min)
            min = dist[i], min_index = i;
    }
    return min_index;
}

void myFunction::printShortestPath(int dist[], int n, int parent[], int src)
{
    cout << "Tujuan \t\tTotal Jarak\tRute Tercepat";

    string kotaAsal = cityNameSearch(src);

    for (int i = 0; i < listData.top; i++)
    {
        string kotaTujuan = cityNameSearch(i);
        // printf("\n%s -> %s\t %d\t %s",
        //        kotaAsal, kotaTujuan, dist[i], kotaAsal);
        cout << "\n"
             << kotaAsal << "->" << kotaTujuan << "\t\t" << dist[i] << "\t\t" << kotaAsal;
        printHubungan(parent, i);
    }
}

void myFunction::printHubungan(int parent[], int i)
{
    if (parent[i] == -1)
        return;
    printHubungan(parent, parent[i]);

    string kotaHubungan = cityNameSearch(i);
    cout << "->" << kotaHubungan;
}

// void myFunction::dijkstraGraph()
// {
//     // listData.top++;
//     int graph[listData.top][listData.top] = {
//         {0, 1, 2, 0, 0, 0},
//         {1, 0, 0, 5, 1, 0},
//         {2, 0, 0, 2, 3, 0},
//         {0, 5, 2, 0, 2, 2},
//         {0, 1, 3, 2, 0, 1},
//         // {0, 0, 0, 2, 1, 0}
//     };
//     // dijkstra(graph);
// }

void myFunction::dijkstra()
{
    int graph[listData.top][listData.top] = {
        {0, listData.dataKota[0].hub[0].jarak, listData.dataKota[0].hub[1].jarak, 0, 0},                                 //0
        {listData.dataKota[1].hub[0].jarak, 0, 0, listData.dataKota[1].hub[1].jarak, listData.dataKota[1].hub[2].jarak}, //1
        {listData.dataKota[2].hub[0].jarak, 0, 0, listData.dataKota[2].hub[1].jarak, 0},                                 //2
        {0, listData.dataKota[3].hub[0].jarak, listData.dataKota[3].hub[1].jarak, 0, listData.dataKota[3].hub[2].jarak}, //3
        {0, listData.dataKota[4].hub[0].jarak, 0, listData.dataKota[4].hub[1].jarak, 0},                                 //4
        // {0, 0, 0, 2, 1, 0}
    };
    string namaKota;
    int src;
    cout << "Masukkan Asal Kota: ";
    cin >> namaKota;

    //konversi nama kota ke index
    src = indexSearch(namaKota);

    int jarak[max];
    bool isTraveled[max] = {0};
    int parent[max];

    for (int i = 0; i < listData.top; i++)
    {
        jarak[i] = INT_MAX;
        parent[src] = -1;
    }

    jarak[src] = 0;

    for (int i = 0; i < listData.top; i++)
    {
        int min = minDistance(jarak, isTraveled);
        isTraveled[min] = true;
        for (int j = 0; j < listData.top; j++)
        {
            // cout << graph[min][j] << endl;
            if (!isTraveled[j] && graph[min][j] && jarak[min] != INT_MAX && jarak[min] + graph[min][j] < jarak[j])
            {
                parent[j] = min;
                jarak[j] = jarak[min] + graph[min][j];
            }
        }
    }

    //Printing
    printShortestPath(jarak, listData.top, parent, src);

    // cout << "Asal\t\tJarak dari asal" << endl;
    // for (int k = 0; k < listData.top; k++)
    // {
    //     char str = 65 + k;
    //     cout << str << "\t\t\t" << jarak[k] << endl;
    // }

    // cout << "Jarak Tercepat " << namaKota << " Menuju E";

    // bool isTraveled[listData.top] = {0};
    // // bool isJalur[max] = {0};
    // int jarak[listData.top] = {INT_MAX};
    // int src;
    // cin >> src;
    // jarak[src] = 0;

    // for (int i = 0; i < listData.top; i++)
    // {
    //     int m = minDistance(jarak, isTraveled);
    //     isTraveled[m] = true;
    //     for (int j = 0; j < listData.top; j++)
    //     {
    //         if (!isTraveled[j] && jarak[m] != INT_MAX && listData.dataKota[m].jarakKota + jarak[m] < INT_MAX)
    //             jarak[j] = jarak[m] + listData.dataKota[m].jarakKota;
    //     }
    // }

    // for (int k = 0; k < 6; k++)
    // {
    //     char str = 65 + k;
    //     cout << str << "\t\t\t" << jarak[k] << endl;
    // }
    // for (int i = 1; i < listData.top; i++)
    // {
    //     if (listData.dataKota[i - 1].jarakKota + listData.dataKota[i].jarakKota < INT_MAX && isTraveled[i - 1] == false)
    //     {
    //         isTraveled[i - 1] = true;
    //         jarak[i] = listData.dataKota[i - 1].jarakKota + listData.dataKota[i].jarakKota;
    //     }
    // }

    // listData.dataKota[0].jarakKota = 0;
    // for (int i = 1; i <= listData.top; i++)
    // {
    //     // cout << jarak[i - 1] << endl;
    //     // listData.dataKota[i-1].jarakKota = jarak[i-1];
    //     if (listData.dataKota[0].jarakKota + listData.dataKota[i].jarakKota > jarak[i])
    //     {
    //         isJalur[i] = true;
    //     }
    //     else if (listData.dataKota[0].jarakKota + listData.dataKota[i].jarakKota <= jarak[i])
    //     {
    //         isJalur[i] = false;
    //     }

    //     // if(jarak[0] > jarak[i])
    //     // {
    //     //     listData.dataKota[0].jarakKota = jarak[0];
    //     //     isJalur[i] = true;
    //     // }
    // }

    // for (int i = 0; i < listData.top; i++)
    // {
    //     cout << isJalur[i] << endl;
    // }
}

// void myFunction::jarakKota()
// {

// }

// void myFunction::hubunganKota()
// {
//     cout << "Masukkan nama kota: ";
//     string kota;
//     cin >> kota;

//     int n = indexSearch(kota);

//     for (int i = 0; i < listData.dataKota[n].nextKota.size(); i++)
//     {
//         cout << listData.dataKota[i].nextKota.front().kotaTujuan << ", ";
//     }
// }