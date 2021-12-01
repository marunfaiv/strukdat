#include <bits/stdc++.h>
using namespace std;
#define max 5
class Testing
{
private:
    struct hubKota
    {
        string kotaTujuan[max];
        int jarak;
        int lastNode;
    }hub;

    struct stack
    {
        int top;
        struct kota
        {
            int idxKota;
            string namaKota;
            vector<struct hubKota> nextKota;
        } dataKota[max];
    } listData;

    void append(string nama)
    {
        listData.dataKota[listData.top].idxKota = listData.top;
        listData.dataKota[listData.top].namaKota = nama;
        listData.top++;
    }

    int searchIndex(string kota)
    {
        int idx;
        for (int i = 0; i < listData.top; i++)
        {
            if (kota == listData.dataKota[i].namaKota)
                idx = listData.dataKota[i].idxKota;
        }
        return idx;
    }

    void connectKota(string asalKota, string tujuanKota, int jarak)
    {
        int id1 = searchIndex(asalKota);
        int id2 = searchIndex(tujuanKota);
        if (id1 >= 0 && id2 >= 0)
        {
            // for (int i = 0; i < listData.dataKota->nextKota.size(); i++)
            // {
            hub.lastNode++;
            hub.kotaTujuan[hub.lastNode] = tujuanKota;
            hub.jarak = jarak;
            // }
            listData.dataKota[id1].nextKota.push_back(hub);
        }
    }

public:
    Testing()
    {
        listData.top = 0;
        hub.lastNode = -1;
        append("A");
        append("B");
        append("C");
        append("D");
        append("E");

        connectKota("A", "B", 1);
        connectKota("A", "C", 2);
        connectKota("B", "D", 5);
        connectKota("B", "E", 1);
        connectKota("C", "D", 2);
        connectKota("D", "E", 3);
        // connectKota("C", "D", 2);
    }

    ~Testing()
    {
        delete this;
    }

    void print()
    {
        cout << "Nama\t\t";
        cout << "Hubungan\n";
        for (int i = 0; i < listData.top; i++)
        {
            cout << listData.dataKota[i].namaKota << "\t\t";
            cout << listData.dataKota[i].nextKota.front().kotaTujuan[i] << endl;
        }
    }
};

int main()
{
    Testing a;

    a.print();
}