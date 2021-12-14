#include "myFunction.h"

// Constructor
myFunction::myFunction()
{
    // this->node = node;
    // this->window = window;
    listData.top = 0;
    // listData.dataKota.lastNode = -1;
    q.belakang = 0;
    q.depan = 0;

    // struct hubKota hub;
    // vector<struct kota> dataKota;

    append("A", 360, 180);
    append("B", 720, 180);
    append("C", 360, 420);
    append("D", 720, 420);
    append("E", 960, 300);

    connectKota("A", "B");
    connectKota("A", "C");
    connectKota("B", "D");
    connectKota("B", "E");
    connectKota("C", "D");
    connectKota("D", "E");
    // node->nodesVisual(window);
}

// Destructor
myFunction::~myFunction()
{
    delete this;
}

// Private Function
void myFunction::append(string nama, int x, int y)
{
    listData.dataKota[listData.top].namaKota = nama;
    listData.dataKota[listData.top].x = x;
    listData.dataKota[listData.top].y = y;
    listData.dataKota[listData.top].lastNode = -1;
    listData.dataKota[listData.top].idxKota = listData.top;
    listData.top++;

    // node->getX(x);
    // node->getY(y);
    // node->getName(nama);
    // node->getTotKota(listData.top);
}

bool myFunction::isFull()
{
    return listData.top == batas - 1;
}

bool myFunction::isEmpty()
{
    return listData.top == 0;
}

bool myFunction::qFull()
{
    return q.belakang == batas;
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

float myFunction::distanceMaker(int x1, int y1, int x2, int y2)
{
    // make rumus pitagorasnya kaka...
    return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
}

// Public Function
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
                // cout << listData.dataKota[0].nextKota.front().kotaTujuan; cout <<  hub.kotaTujuan << ", ";
                // cout << listData.dataKota[j].nextKota.front().kotaTujuan << ", ";
            }
            cout << listData.dataKota[i].hub[listData.dataKota[i].lastNode].tujuanKota << "\t\t";

            for (int k = 0; k < listData.dataKota[i].lastNode; k++)
            {
                cout << listData.dataKota[i].hub[k].jarak << ", ";
            }
            cout << listData.dataKota[i].hub[listData.dataKota[i].lastNode].jarak << " ";
        }
        cout << endl;
    }
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
        append(nama, x, y);
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

void myFunction::connectKota(string kotaAsal, string kotaTujuan)
{
    int id1 = indexSearch(kotaAsal);
    int id2 = indexSearch(kotaTujuan);
    float jarak = distanceMaker(listData.dataKota[id1].x, listData.dataKota[id1].y, listData.dataKota[id2].x, listData.dataKota[id2].y);

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
    }
    else
        cout << "Sing nggenah ae...\n";
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
    // cout << listData.dataKota[0].hub[0].tujuanKota << endl;
    // cout << listData.dataKota[0].hub[1].tujuanKota << endl;

    // cout << getX() << "\n";
    // cout << getY() << "\n";
    // cout << getName() << "\n";
    // cout << listData.dataKota[0].hub[0].jarak;
    // cout << "\n";
    // cout << listData.dataKota[1].hub[0].jarak;
    // cout << "\n";
    // cout << listData.dataKota[2].hub[0].jarak;
    // cout << "\n";
    // cout << listData.dataKota[3].hub[0].jarak;
    // cout << "\n";
    // checkHubungan("A", "B");
    // checkHubungan("A", "E");
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

void myFunction::printAllPath(int dist[], int n, int parent[], int src)
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

void myFunction::printSinglePath(int dist[], int n, int parent[], int src, int dst)
{
    cout << "Tujuan\t";
    cout << "Jalur\t\t";
    cout << "Jarak";

    string kotaAsal = cityNameSearch(src);
    string kotaTujuan = cityNameSearch(dst);

    cout << "\n"
         << kotaAsal << "->" << kotaTujuan << "\t" << kotaAsal;
    // string kotaLanjutan = cityNameSearch(dst);
    printHubungan(parent, dst);
    cout << "\t\t" << dist[dst];
}

void myFunction::printHubungan(int parent[], int i)
{
    if (parent[i] == -1)
        return;
    printHubungan(parent, parent[i]);
    string kotaHubungan = cityNameSearch(i);
    cout << "->" << kotaHubungan;
}

void myFunction::dijkstra()
{
    int graph[listData.top][listData.top] = {
        {0, listData.dataKota[0].hub[0].jarak, listData.dataKota[0].hub[1].jarak, 0, 0},                                 // A
        {listData.dataKota[1].hub[0].jarak, 0, 0, listData.dataKota[1].hub[1].jarak, listData.dataKota[1].hub[2].jarak}, // B
        {listData.dataKota[2].hub[0].jarak, 0, 0, listData.dataKota[2].hub[1].jarak, 0},                                 // C
        {0, listData.dataKota[3].hub[0].jarak, listData.dataKota[3].hub[1].jarak, 0, listData.dataKota[3].hub[2].jarak}, // D
        {0, listData.dataKota[4].hub[0].jarak, 0, listData.dataKota[4].hub[1].jarak, 0},                                 // E
        // {0, 0, 0, 2, 1, 0}
    };
    string namaKota, tujuanKota;
    int src, dst, chc;

    cout << "Single Path(1) / All Path(2): ";
    cin >> chc;
    cout << "\nMasukkan Asal Kota: ";
    cin >> namaKota;

    // konversi nama kota ke index
    src = indexSearch(namaKota);

    int jarak[batas];
    bool isTraveled[batas] = {0};
    int parent[batas];

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

    // Printing
    if (chc == 1)
    {
        cout << "Masukkan Tujuan Kota: ";
        cin >> tujuanKota;
        dst = indexSearch(tujuanKota);
        printSinglePath(jarak, listData.top, parent, src, dst);
    }
    else if (chc == 2)
        printAllPath(jarak, listData.top, parent, src);
}

bool myFunction::checkHubungan(string kotaA, string kotaB)
{
    int src = indexSearch(kotaA);
    int dst = indexSearch(kotaB);

    if (src >= 0 && dst >= 0)
    {
        for (int i = 0; i < listData.top; i++)
        {

            if (listData.dataKota[src].hub[i].tujuanKota == listData.dataKota[dst].namaKota)
            {
                // cout << "Hubungane enek bro..\n";
                return true;
            }
        }
        return false;
    }
    else
        return false;
}