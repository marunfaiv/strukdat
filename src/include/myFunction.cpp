#include "myFunction.h"

//Constructor
myFunction::myFunction()
{
    listData.top = 0;
    listData.dataKota->lastNode = -1;
    q.belakang = 0;
    q.depan = 0;
}

//Destructor
myFunction::~myFunction()
{
    delete this;
}

//Private Function
void myFunction::append(string nama, int x, int y)
{
    listData.dataKota[listData.top].namaKota = nama;
    listData.dataKota[listData.top].x = x;
    listData.dataKota[listData.top].y = y;
    listData.dataKota[listData.top].lastNode = -1;
    listData.top++;
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
    for (int i = listData.top; i >= 0; i--)
    {
        if (listData.dataKota[i].namaKota == nama)
        {
            // cout << "Kota berada pada index ke-" << i << endl;
            return i;
        }
    }
    return -1;
}

//Public Function
void myFunction::print()
{
    int chc = 0;
    cout << "Data dari Push atau Antrian \n1 = Push \n2 = Queue " << endl;
    cin >> chc;

    cout << "\t\tDATA KOTA\n";
    // header
    cout << "Nama:\t";
    cout << "X:\t";
    cout << "Y:\t";
    cout << "Hubungan:\n";
    if (chc == 1)
    {
        if (isEmpty())
            cout << "Ga enek sing di print..\n";
        // isi
        for (int i = 0; i < listData.top; i++)
        {
            cout << listData.dataKota[i].namaKota << "\t";

            cout << listData.dataKota[i].x << "\t";
            cout << listData.dataKota[i].y << "\t";

            if (listData.dataKota[i].lastNode == -1)
                cout << "- ";
            else
            {
                for (int j = 0; j < listData.dataKota[i].lastNode; j++)
                    cout << listData.dataKota[i].hubKota[j] << ", ";
                cout << listData.dataKota[i].hubKota[listData.dataKota[i].lastNode] << " ";
            }
            cout << endl;
        }
    }
    else if (chc == 2)
    {
        if (qEmpty())
            cout << "Antrian kosong bosquu...";
        // isi
        for (int i = q.depan; i < q.belakang; i++)
        {
            cout << q.qData[i].namaKota << "\t";

            cout << q.qData[i].x << "\t";
            cout << q.qData[i].y << "\t";
            cout << endl;
        }
    }
}

void myFunction::pushData()
{
    string nama;
    int x, y;
    if (isFull())
        cout << "Wes full bro..." << endl;
    else
    {
        cout << "Masukkan Nama Kota: ";
        cin >> nama;
        cout << "X dan Y: ";
        cin >> x >> y;
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
    int id1 = indexSearch(kota1);
    int id2 = indexSearch(kota2);

    if (id1 >= 0 and id2 >= 0)
    {
        listData.dataKota[id1].lastNode++;
        listData.dataKota[id1].hubKota[listData.dataKota[id1].lastNode] = kota2;
        listData.dataKota[id1].nextNode[listData.dataKota[id1].lastNode] = id2;

        /* ini untuk connect 2 arah */
        //  listData.dataKota[id2].lastNode++;
        //  listData.dataKota[id2].hubKota[listData.dataKota[id2].lastNode] = kota1;
        //  listData.dataKota[id2].nextNode[listData.dataKota[id2].lastNode] = id1;
    }
    else
        cout << "Kuto ne ra temu bos...\n";
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