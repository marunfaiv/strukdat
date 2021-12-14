// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // #define max 5
// // // class Testing
// // // {
// // // private:
// // //     struct hubKota
// // //     {
// // //         string kotaTujuan[max];
// // //         int jarak;
// // //         int lastNode;
// // //     }hub;

// // //     struct stack
// // //     {
// // //         int top;
// // //         struct kota
// // //         {
// // //             int idxKota;
// // //             string namaKota;
// // //             vector<struct hubKota> nextKota;
// // //         } dataKota[max];
// // //     } listData;

// // //     void append(string nama)
// // //     {
// // //         listData.dataKota[listData.top].idxKota = listData.top;
// // //         listData.dataKota[listData.top].namaKota = nama;
// // //         listData.top++;
// // //     }

// // //     int searchIndex(string kota)
// // //     {
// // //         int idx;
// // //         for (int i = 0; i < listData.top; i++)
// // //         {
// // //             if (kota == listData.dataKota[i].namaKota)
// // //                 idx = listData.dataKota[i].idxKota;
// // //         }
// // //         return idx;
// // //     }

// // //     void connectKota(string asalKota, string tujuanKota, int jarak)
// // //     {
// // //         int id1 = searchIndex(asalKota);
// // //         int id2 = searchIndex(tujuanKota);
// // //         if (id1 >= 0 && id2 >= 0)
// // //         {
// // //             // for (int i = 0; i < listData.dataKota->nextKota.size(); i++)
// // //             // {
// // //             hub.lastNode++;
// // //             hub.kotaTujuan[hub.lastNode] = tujuanKota;
// // //             hub.jarak = jarak;
// // //             // }
// // //             listData.dataKota[id1].nextKota.push_back(hub);
// // //         }
// // //     }

// // // public:
// // //     Testing()
// // //     {
// // //         listData.top = 0;
// // //         hub.lastNode = -1;
// // //         append("A");
// // //         append("B");
// // //         append("C");
// // //         append("D");
// // //         append("E");

// // //         connectKota("A", "B", 1);
// // //         connectKota("A", "C", 2);
// // //         connectKota("B", "D", 5);
// // //         connectKota("B", "E", 1);
// // //         connectKota("C", "D", 2);
// // //         connectKota("D", "E", 3);
// // //         // connectKota("C", "D", 2);
// // //     }

// // //     ~Testing()
// // //     {
// // //         delete this;
// // //     }

// // //     void print()
// // //     {
// // //         cout << "Nama\t\t";
// // //         cout << "Hubungan\n";
// // //         for (int i = 0; i < listData.top; i++)
// // //         {
// // //             cout << listData.dataKota[i].namaKota << "\t\t";
// // //             cout << listData.dataKota[i].nextKota.front().kotaTujuan[i] << endl;
// // //         }
// // //     }
// // // };

// // // int main()
// // // {
// // //     Testing a;

// // //     a.print();
// // // }

// // #include <bits/stdc++.h>
// // // #include <SFML/Window.hpp>
// // // #include <SFML/Graphics.hpp>
// // // Mulai dari 0

// // using namespace std;
// // // using namespace sf;

// // float pitagoras(float x1, float y1, float x2, float y2)
// // {

// //     return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
// // }

// // class DbKota
// // {
// // private:
// //     // properties
// //     // int last_node;
// //     int banyak_kota;

// // public:
// //     // properties
// //     struct kota_t
// //     {
// //         string nama;
// //         char *nama_serial;
// //         int x;
// //         int y;
// //         string hubungan_kota[100];
// //         int hubungan_kota_pos[100];
// //         int tanda_akhir_hubungan_kota;
// //         // int next_node;
// //     };

// //     kota_t kota[100];

// //     // method

// //     DbKota()
// //     {
// //         // last_node = -1;
// //         banyak_kota = 0;
// //     }
// //     ~DbKota()
// //     {
// //         // destruktor
// //     }

// //     void push(string nama_kota, int x, int y)
// //     {
// //         // last_node++;
// //         banyak_kota++;
// //         kota[banyak_kota - 1].nama = nama_kota;
// //         kota[banyak_kota - 1].x = x;
// //         kota[banyak_kota - 1].y = y;
// //         // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
// //         kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;
// //         // kota[last_node].next_node = -1;
// //         // kota[banyak_kota - 1].nama_serial = new char[nama_kota.size() + 1];
// //         // strcpy(kota[banyak_kota - 1].nama_serial, kota[banyak_kota - 1].nama.c_str());
// //     }
// //     void push(kota_t src)
// //     {
// //         banyak_kota++;
// //         // printf("alamat tekan push: %p\n", &kota[banyak_kota - 1]);
// //         kota[banyak_kota - 1] = src;
// //         // memcpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
// //         // memset(&kota[banyak_kota-1],src,sizeof(kota[banyak_kota]));
// //         // memccpy(&kota[banyak_kota - 1], &src, sizeof(kota[banyak_kota - 1]));
// //     }

// //     kota_t pop()
// //     {
// //         kota_t buff, null;
// //         // memcpy(&buff, &kota[banyak_kota - 1], sizeof(buff));
// //         buff = kota[banyak_kota - 1];
// //         // memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
// //         kota[banyak_kota - 1] = null;
// //         banyak_kota--;
// //         return buff;
// //     }

// //     void pop(kota_t *result)
// //     {
// //         kota_t null;
// //         // printf("fungsi: %p\n", result);
// //         // printf("asli pop: %s", kota[banyak_kota - 1].nama.c_str());
// //         // printf("alamat sakdoronge %p\n", &kota[banyak_kota - 1]);
// //         *result = kota[banyak_kota - 1];
// //         kota[banyak_kota - 1] = null;
// //         // memset(&kota[banyak_kota - 1], 0, sizeof(kota[banyak_kota]));
// //         // printf("alamat sakmarine %p\n", &kota[banyak_kota - 1]);
// //         // printf("hasil pop fungsi: %s\n", kota[banyak_kota - 1].nama.c_str());
// //         // printf("waetfcthweftvewjqewfqweyj\n");
// //         banyak_kota--;
// //         // printf("hasil pop: %s", result->nama.c_str());
// //     }

// //     void justPop()
// //     {
// //         kota_t null;
// //         kota[banyak_kota - 1] = null;
// //         // memset(&kota[banyak_kota], false, sizeof(kota[banyak_kota]));
// //         banyak_kota--;
// //     }

// //     void enqueue(kota_t src)
// //     {
// //         // remove(0);
// //         insert(0, src.nama, src.x, src.y);
// //     }
// //     void enqueue(string nama, int x, int y)
// //     {
// //         insert(0, nama, x, y);
// //     }
// //     void dequeue(kota_t *res)
// //     {
// //         *res = kota[0];
// //         remove(0);
// //     }
// //     kota_t dequeue()
// //     {
// //         kota_t buff;
// //         buff = kota[0];
// //         remove(0);
// //         return buff;
// //     }
// //     void justDequeue()
// //     {
// //         remove(0);
// //     }

// //     void remove(int posisi)
// //     {
// //         posisi++;
// //         for (int i = posisi - 1; i < banyak_kota; i++) // mengiri
// //         {
// //             kota[i] = kota[i + 1];
// //         }

// //         kota[banyak_kota - 1].nama = false;
// //         kota[banyak_kota - 1].x = false;
// //         kota[banyak_kota - 1].y = false;
// //         // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
// //         kota[banyak_kota - 1].tanda_akhir_hubungan_kota = -1;

// //         banyak_kota--;
// //     }

// //     void removeByName(string nama_kota)
// //     {
// //         remove(searchByName(nama_kota));
// //     }

// //     void insert(int posisi, string nama_kota, int x, int y)
// //     {
// //         kota_t null; // menyiapkan ruang kosong
// //         banyak_kota++;
// //         for (int i = banyak_kota; i >= posisi; i--) // menganan
// //         {
// //             kota[i + 1] = kota[i];
// //         }
// //         // printf("hubungan: %s", null.hubungan_kota[0].c_str());
// //         null.tanda_akhir_hubungan_kota = -1; // persiapan tambahan
// //         kota[posisi] = null;
// //         kota[posisi].nama = nama_kota;
// //         kota[posisi].x = x;
// //         kota[posisi].y = y;
// //         // memset(kota[last_node].hubungan_kota, -1, sizeof(kota[last_node].hubungan_kota));
// //         // kota[last_node].tanda_akhir_hubungan_kota = -1;
// //         // kota[posisi].next_node = -1;
// //     }

// //     void show(int more = 0)
// //     {
// //         int panjang_nama = 0;
// //         int panjang_terdekat = 0;
// //         if (!more)
// //         {
// //             for (int i = 0; i < banyak_kota; i++)
// //             {
// //                 // printf("iter-%d\n", i);
// //                 if (kota[i].nama.size() < 0x8)
// //                     cout << kota[i].nama << "\t\t";
// //                 else if (kota[i].nama.size() >= 0x8)
// //                     cout << kota[i].nama << "\t";
// //                 cout << kota[i].x << "\t";
// //                 cout << kota[i].y << "\t";
// //                 if (kota[i].tanda_akhir_hubungan_kota == -1)
// //                     printf("- ");
// //                 else
// //                 {
// //                     for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
// //                     {
// //                         cout << kota[i].hubungan_kota[v] << ", ";
// //                     }
// //                     cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
// //                 }
// //                 cout << endl;
// //             }
// //         }
// //         else
// //         {
// //             // header
// //             for (int i = 0; i < banyak_kota; i++)
// //             {
// //                 if (kota[i].nama.size() < 0x8)
// //                     panjang_nama = 0;
// //                 else if (kota[i].nama.size() >= 0x8)
// //                     panjang_nama = 1;

// //                 if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
// //                     panjang_terdekat = 0;
// //                 else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
// //                     panjang_terdekat = 1;
// //             }

// //             if (panjang_nama == 0)
// //                 printf("Nama \t");
// //             else if (panjang_nama == 1)
// //                 printf("Nama \t\t");

// //             printf("X\t");

// //             printf("Y\t");

// //             if (panjang_terdekat = 0)
// //                 printf("Terdekat");
// //             else if (panjang_terdekat = 1)
// //                 printf("Terdekat\t");

// //             printf("Hubungan ");

// //             printf("\n");

// //             // isi
// //             for (int i = 0; i < banyak_kota; i++)
// //             {
// //                 // printf("iter-%d\t", i); // untuk debug index
// //                 if (kota[i].nama.size() < 0x8)
// //                     cout << kota[i].nama << "\t\t";
// //                 else if (kota[i].nama.size() >= 0x8)
// //                     cout << kota[i].nama << "\t";

// //                 cout << kota[i].x << "\t";

// //                 cout << kota[i].y << "\t";

// //                 if (cariKotaTerdekatStr(kota[i].nama).size() < 0x8)
// //                     cout << cariKotaTerdekatStr(kota[i].nama) << "\t\t";
// //                 else if (cariKotaTerdekatStr(kota[i].nama).size() >= 0x8)
// //                     cout << cariKotaTerdekatStr(kota[i].nama) << "\t";
// //                 // cout << cariKotaTerdekatStr(kota[i].nama) << " ";

// //                 if (kota[i].tanda_akhir_hubungan_kota == -1)
// //                     printf("- ");
// //                 else
// //                 {
// //                     for (int v = 0; v < kota[i].tanda_akhir_hubungan_kota; v++) // print hubungan
// //                     {
// //                         cout << kota[i].hubungan_kota[v] << ", ";
// //                     }
// //                     cout << kota[i].hubungan_kota[kota[i].tanda_akhir_hubungan_kota] << " ";
// //                 }
// //                 cout << endl;
// //             }
// //         }
// //         printf("\n");
// //     }

// //     int searchByName(string nama_kota)
// //     {
// //         for (int i = 0; i < banyak_kota; i++)
// //         {
// //             if (nama_kota == kota[i].nama)
// //             {
// //                 return i;
// //             }
// //         }
// //         // kalo sampek sini berarti kota gk ditemukan
// //         //  printf("kota gk ditemukan\n");
// //         return -1;
// //     }
// //     void searchWithoutReturn(string nama_kota)
// //     {
// //         for (int i = 0; i < banyak_kota; i++)
// //         {
// //             if (nama_kota == kota[i].nama)
// //             {
// //                 printf("%s ada pada index ke-%d\n", nama_kota.c_str(), i);
// //                 return;
// //             }
// //         }
// //         printf("Kota tidak ditemukan\n");
// //     }

// //     void searchByPos(int posisi)
// //     {
// //         cout << "Kota pada posisi ke-" << posisi << " adalah " << kota[posisi].nama << endl;
// //     }
// //     void connect1arah(string src, string dst)
// //     {
// //         int src_pos = searchByName(src);
// //         int dst_pos = searchByName(dst);
// //         if (src_pos >= 0 && dst_pos >= 0)
// //         {

// //             kota[src_pos].tanda_akhir_hubungan_kota++;
// //             kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
// //             kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
// //         }
// //         else
// //             printf("Invalid name\n");
// //     }
// //     void connect2arah(string src, string dst)
// //     {
// //         int src_pos = searchByName(src);
// //         int dst_pos = searchByName(dst);
// //         if (src_pos >= 0 && dst_pos >= 0)
// //         {
// //             kota[dst_pos].tanda_akhir_hubungan_kota++;
// //             kota[dst_pos].hubungan_kota[kota[dst_pos].tanda_akhir_hubungan_kota] = src;
// //             kota[dst_pos].hubungan_kota_pos[kota[dst_pos].tanda_akhir_hubungan_kota] = src_pos;

// //             kota[src_pos].tanda_akhir_hubungan_kota++;
// //             kota[src_pos].hubungan_kota[kota[src_pos].tanda_akhir_hubungan_kota] = dst;
// //             kota[src_pos].hubungan_kota_pos[kota[src_pos].tanda_akhir_hubungan_kota] = dst_pos;
// //         }
// //         else
// //             printf("Invalid name\n");
// //     }

// //     // PERCOBAAN, kendala belum menemukan solusi tepat untuk pindah cabang pencarian
// //     void cariHubungan(int dst, int temp[100], int *total_hub, int iter)
// //     {
// //         // Linear search
// //         int temp_iter = iter;
// //         for (int i = 0; i < banyak_kota; i++)
// //         {
// //             if (kota[i].tanda_akhir_hubungan_kota > -1)
// //             {
// //                 for (int j = 0; j <= kota[i].tanda_akhir_hubungan_kota; j++)
// //                 {
// //                     // printf("hub: %d dengan %d, ", kota[i].hubungan_kota_pos[j], dst);
// //                     if (kota[i].hubungan_kota_pos[j] == dst)
// //                     {
// //                         temp[temp_iter] = i;
// //                         temp_iter++;
// //                     }
// //                 }
// //             }
// //             // printf("sudah\n");
// //         }
// //         // printf("ier: %d\n", temp_iter);
// //         if (temp_iter == 0)
// //             printf("Tdk punya hubungan..\n");
// //         else
// //             *total_hub = temp_iter;
// //     }
// //     void cariRute(string src, string dst)
// //     {
// //         int temp[100], total_hub = 0, hasil[100];
// //         int tanda_hasil = 0;
// //         int src_pos = searchByName(src);
// //         int dst_pos = searchByName(dst);
// //         if (src_pos >= 0 && dst_pos >= 0)
// //         {
// //             int i = 0;
// //             // while (temp[i] != src_pos)
// //             // {
// //             temp[0] = dst_pos;
// //             int j = 0;
// //             while (temp[0] != src_pos)
// //             {
// //                 // printf("j: %d\n", j);
// //                 if (j >= banyak_kota - 1)
// //                 {
// //                     j = 0;
// //                     i++;
// //                 }
// //                 cariHubungan(temp[i], temp, &total_hub, i);
// //                 j++;
// //                 if (total_hub > 0)
// //                 {
// //                     hasil[tanda_hasil] = temp[i];
// //                     tanda_hasil++;
// //                 }
// //             }
// //             //     i++;
// //             // }
// //         }
// //         // printf("temp0: %d\n", temp[0]);
// //         if (temp[0] == searchByName(src))
// //         { // printf("hasil: %d", temp[0]);
// //             // printf("Rute: ");
// //             cout << "Rute " << src << " ke " << dst << " : " << endl;
// //             for (int i = tanda_hasil - 1; i >= 0; i--)
// //             {
// //                 // printf("awukehhkcuakuaew %d ", hasil[i]);
// //                 // printf("%");
// //                 cout << kota[hasil[i]].nama << " -> ";
// //             }
// //             cout << dst << endl;
// //         }
// //         else
// //         {
// //             printf("Tidak ditemukan jalan..");
// //         }
// //     }
// //     int cariKotaTerdekat(string kota_yang_ingin_dicari)
// //     {
// //         int pos = searchByName(kota_yang_ingin_dicari);
// //         float min = 9999999999;
// //         int min_pos = pos;
// //         for (int i = 0; i < banyak_kota; i++)
// //         {
// //             if (i != pos)
// //             {
// //                 // printf("min: %f ", min);
// //                 // printf("jarak %s: %f\n", kota[i].nama.c_str(), pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y));
// //                 if (min >= pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y))
// //                 {
// //                     min = pitagoras(kota[pos].x, kota[pos].y, kota[i].x, kota[i].y);
// //                     min_pos = i;
// //                 }
// //             }
// //         }
// //         return min_pos;
// //     }
// //     string cariKotaTerdekatStr(string kota_yang_ingin_dicari)
// //     {
// //         return kota[cariKotaTerdekat(kota_yang_ingin_dicari)].nama;
// //     }
// // };

// // class Iface
// // {
// // private:
// //     DbKota *DB; // simpan alamat DB

// // public:
// //     Iface(DbKota *DB)
// //     {
// //         this->DB = DB;
// //     }
// //     ~Iface()
// //     {
// //     }
// //     void pop(DbKota::kota_t *result)
// //     {
// //         int pilihan;
// //         printf("0. exit\n");
// //         printf("1. Pop dengan hasilnya disimpan dalam variabel buff pada main\n");
// //         printf("2. Pop tanpa menyimpan hasilnya\n");
// //         scanf("%d", &pilihan);

// //         if (!pilihan)
// //             return;
// //         switch (pilihan)
// //         {
// //         case 1:
// //             DB->pop(result);
// //             break;
// //         case 2:
// //             DB->justPop();
// //             break;

// //         default:
// //             break;
// //         }
// //     }
// //     void hub()
// //     {
// //         int pilihan;
// //         string src, dst;
// //         printf("0. exit\n");
// //         printf("1. hubungakn 1 arah\n");
// //         printf("2. hubungkan 2 arah\n");
// //         scanf("%d", &pilihan);

// //         if (!pilihan)
// //             return;
// //         switch (pilihan)
// //         {
// //         case 1:
// //             printf("Kota asal? ");
// //             getline(cin, src);
// //             // getline(cin, src);
// //             printf("Tujuan? ");
// //             getline(cin, dst);
// //             // printf("sampek kene?");
// //             DB->connect1arah(src, dst);
// //             break;
// //         case 2:
// //             printf("Kota asal? ");
// //             getline(cin, src);
// //             printf("Tujuan? ");
// //             getline(cin, dst);
// //             DB->connect2arah(src, dst);
// //             break;

// //         default:
// //             break;
// //         }
// //     }
// //     void push()
// //     {
// //         string nama;
// //         int x, y;
// //         printf("Nama kota?: ");
// //         // cin >> nama;
// //         getline(cin, nama);
// //         printf("X: ");
// //         scanf("%d", &x);
// //         printf("Y: ");
// //         scanf("%d", &y);
// //         DB->push(nama, x, y);
// //     }
// //     void enqueue()
// //     {
// //         string nama;
// //         int x, y;
// //         printf("Nama kota?: ");
// //         // cin >> nama;
// //         getline(cin, nama);
// //         printf("X: ");
// //         scanf("%d", &x);
// //         printf("Y: ");
// //         scanf("%d", &y);
// //         DB->enqueue(nama, x, y);
// //     }
// //     void dequeue()
// //     {
// //         DB->dequeue();
// //     }
// //     void insert()
// //     {
// //         string nama;
// //         int x, y, pos;
// //         printf("Posisi index?: ");
// //         scanf("%d", &pos);
// //         printf("Nama kota?: ");
// //         // cin >> nama;
// //         getline(cin, nama);
// //         printf("X: ");
// //         scanf("%d", &x);
// //         printf("Y: ");
// //         scanf("%d", &y);
// //         DB->insert(pos, nama, x, y);
// //     }
// //     void remove()
// //     {
// //         int pilihan;
// //         string nama;
// //         int index;
// //         printf("0. exit\n");
// //         printf("1. hapus berdasarkan index\n");
// //         printf("2. hapus berdasarkan nama kota\n");
// //         scanf("%d", &pilihan);

// //         if (!pilihan)
// //             return;
// //         switch (pilihan)
// //         {
// //         case 1:
// //             printf("Masukkan index yang ingin dihapus: ");
// //             scanf("%d", &index);
// //             DB->remove(index);
// //             break;
// //         case 2:
// //             printf("Masukkan nama kota yang ingin dihapus: \n");
// //             getline(cin, nama);
// //             DB->removeByName(nama);
// //             break;

// //         default:
// //             break;
// //         }
// //     }
// //     void cari()
// //     {
// //         int pilihan;
// //         string nama;
// //         int index;
// //         printf("0. exit\n");
// //         printf("1. cari berdasarkan index\n");
// //         printf("2. cari berdasarkan nama kota\n");
// //         scanf("%d", &pilihan);

// //         if (!pilihan)
// //             return;
// //         switch (pilihan)
// //         {
// //         case 1:
// //             printf("Masukkan index yang ingin dicari: ");
// //             scanf("%d", &index);
// //             DB->searchByPos(index);
// //             break;
// //         case 2:
// //             printf("Masukkan nama kota yang ingin dicari: \n");
// //             getline(cin, nama);
// //             // cin.getline(nama);
// //             // DB->searchByName(nama);
// //             DB->searchWithoutReturn(nama);
// //             break;

// //         default:
// //             break;
// //         }
// //     }
// //     void graph()
// //     {
// //         // int offset_x=400;
// //         // int offset_y=300;
// //         // RenderWindow Window(VideoMode(800, 600), "Graph");
// //         // Event event_handler;
// //         // while (1)
// //         // {
// //         //     //...
// //         // }
// //     }
// // };

// // int main()
// // {
// //     int iface_switch = 0;
// //     DbKota DB;
// //     DbKota::kota_t buff;
// //     Iface interface(&DB);

// //     DB.push("Atlantis", 0, 0);
// //     DB.push("Bikini Bottom", 50, 50);
// //     DB.push("Cilacap", 50, 0);
// //     DB.push("Dimmsdale", 100, 100);
// //     DB.push("Eindhoven", 100, 50);
// //     DB.push("Flores", 100, 0);
// //     DB.push("Garut", 100, 25);
// //     DB.push("Honduras", 100, -25);
// //     DB.push("Istanbul", 50, -50);

// //     DB.connect1arah("Atlantis", "Bikini Bottom");
// //     DB.connect1arah("Atlantis", "Cilacap");
// //     DB.connect1arah("Atlantis", "Istanbul");
// //     DB.connect1arah("Bikini Bottom", "Flores");
// //     DB.connect1arah("Bikini Bottom", "Eindhoven");
// //     DB.connect1arah("Bikini Bottom", "Dimmsdale");
// //     DB.connect1arah("Cilacap", "Honduras");
// //     DB.connect1arah("Cilacap", "Garut");
// //     // DB.connect1arah("Istanbul", "Istanbul");
// //     // DB.connect1arah("Atlantis", "Istanbul");

// //     // DB.connect2arah("Jember", "Haven");
// //     // DB.connect2arah("Konoha", "Atlantis");
// //     // DB.connect2arah("Haven", "Bikini Bottom");
// //     // DB.connect2arah("Bikini Bottom", "Dimmsdale");

// //     // DB.insert(2, "sby", 12, 23);
// //     // DB.show(1);
// //     // DB.searchByName("sby");
// //     // DB.searchByPos(2);
// //     // DB.remove(2);
// //     // DB.removeByName("Cilacap");

// //     // printf("hasil %d", DB.searchByName("Cilacap"));

// //     // buff = DB.pop();
// //     // DB.pop(&buff);
// //     // DB.enqueue(buff);
// //     // DB.show(1);
// //     // printf("main: %p\n", &buff);
// //     // printf("hasil pop: %s", buff.nama.c_str());
// //     // DB.dequeue(&buff);
// //     // DB.push(buff);
// //     // DB.show(1);
// //     // printf("buri\n");
// //     // DB.cariRute("Jember", "Dimmsdale");
// //     // DB.cariRute("Jember", "Konoha");

// //     // printf("%f", pitagoras(2, 0, 5, 4));
// //     // printf("%d\n", DB.cariKotaTerdekat("Jember"));
// //     // printf("%s\n", DB.cariKotaTerdekatStr("Jember").c_str());
// //     // DB.cariKotaTerdekat("Jember");

// //     // DB.show(1);
// //     // int coba = 8;
// //     // if (coba == 0x8)
// //     //     printf("%x\n", coba);
// //     // printf("%x\n", 69);

// //     // string dummy;
// //     // printf("input anything to contine\n");
// //     // getline(cin, dummy);

// //     while (1)
// //     {
// //         printf("0. exit\n");
// //         printf("1. push\n");
// //         printf("2. pop\n");
// //         printf("3. tambahkan kota di indeks pertama (enqueue)\n");
// //         printf("4. ambil kota dari indeks pertama (dequeue)\n");
// //         printf("5. masukkan kota\n");
// //         printf("6. hapus kota\n");
// //         printf("7. cari kota\n");
// //         printf("8. hubungkan kota\n");
// //         printf("9. tampilkan seluruh kota\n");
// //         printf("10. graph hubungan kota\n");
// //         scanf("%d", &iface_switch);
// //         if (!iface_switch)
// //             break;
// //         switch (iface_switch)
// //         {
// //         case 1:
// //             interface.push();
// //             break;
// //         case 2:
// //             interface.pop(&buff);
// //             break;
// //         case 3:
// //             interface.enqueue();
// //             break;
// //         case 4:
// //             interface.dequeue();
// //             break;
// //         case 5:
// //             interface.insert();
// //             break;
// //         case 6:
// //             interface.remove();
// //             break;
// //         case 7:
// //             interface.cari();
// //             break;
// //         case 8:
// //             interface.hub();
// //             break;
// //         case 9:
// //             DB.show(1);
// //             break;
// //         case 10:
// //             // Untuk graph saya rencana menggunakan SFML pak.. tapi karena monitor laptap saya rusak sejak hari jumat tanggal 15 oktober sampai hari ini tanggal 24 oktoer masih elum fix menyebabkan saya tidak bisa melakukan percobaan dengan graph untuk menampilkan hubungan kotanya pak..
// //             break;

// //         default:
// //             break;
// //         }
// //     }

// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <math.h>
// #include <iomanip>
// #include <graphics.h>

// using namespace std;

// struct KotaNext
// {
//     string NamaNext;
//     float distance;
// };

// struct Kota
// {
//     float TK;
//     string NamaKota;
//     string visited;
//     float x;
//     float y;
//     vector<KotaNext> Next;
// };

// vector<Kota> ListKota;
// vector<string> KotaTerpendek;

// int Search(string NamaKota)
// {
//     int ikota = -1;
//     for (int i = 0; i<ListKota.size();i++)
//     {
//         string s =ListKota[i].NamaKota;
//         if (NamaKota.compare(s)==0)
//         {
//             ikota = i;
//             break;
//         }

//     }
//     return ikota;
// }

// void Append(string NamaKota,float x,float y)
// {
//     Kota temp;
//     temp.TK=999;
//     temp.NamaKota = NamaKota;
//     temp.x = x;
//     temp.y = y;
//     ListKota.push_back(temp);
// }

// void Connect(string sDari, string sKe)
// {
//     int n1,n2;
//     n1 = Search(sDari);
//     n2 = Search(sKe);
//     if ((n1>=0)&&(n2>=0))
//     {
//         KotaNext temp;
//         temp.NamaNext = sKe;
//         float  x1= ListKota[n1].x;
//         float  y1= ListKota[n1].y;
//         float  x2= ListKota[n2].x;
//         float  y2= ListKota[n2].y;

//         temp.distance  = sqrt(pow(x2-x1, 2) + pow(y2-y1 , 2));
//         ListKota[n1].Next.push_back(temp);

//         temp.NamaNext = sDari;;
//         ListKota[n2].Next.push_back(temp);
//     }
// }

// void initDjikstra()
// {
//     KotaTerpendek.clear();
//     for (int i=0;i<ListKota.size();i++)
//     {
//         ListKota[i].TK =999;
//         ListKota[i].visited.clear();
//     }
// }

// void Dijkstra(string KotaAsal,string KotaTujuan, float TK, string visited)
// {
//     string snext;
//     int n = Search(KotaAsal);
//     int m = Search(KotaTujuan);

//     if(TK > ListKota[n].TK){
//         return;
//     }

//     ListKota[n].TK = TK;
//     ListKota[n].visited = visited;

//     if(n == m)
//     {
//         return;
//     }

//     for(int i=0; i<ListKota[n].Next.size(); i++){
//         snext = ListKota[n].Next[i].NamaNext;
//         float distance = ListKota[n].Next[i].distance;
//         Dijkstra(snext, KotaTujuan, TK+distance, visited+snext);
//     }
// }

// //FUNGSI GAMBAR
// void Draw()
// {
//     for (int i = 0; i<ListKota.size(); i++)
//     {
//         float x1 = ListKota[i].x*20;
//         float y1 = getmaxy()-ListKota[i].y*20;
//         //HUBUNGKAN
//         for(int j=0; j<ListKota[i].Next.size(); j++){
//             string KotaNext = ListKota[i].Next[j].NamaNext;
//             int n=Search(KotaNext);
//             float x2 = ListKota[n].x*20;
//             float y2 = getmaxy()-ListKota[n].y*20;
//             setlinestyle(1, 0, 1);
//             line(x1,y1,x2,y2);
//             setlinestyle(0, 0, 2);
//         }
//         //LINGKARAN
//         char* Kota = &ListKota[i].NamaKota[0];
//         circle(x1,y1,10);
//         setcolor(WHITE);
//         settextstyle(8,0,1);
//         outtextxy(x1,y1+10, Kota);
//     }
// }
// void visualisasiDijkstra(int n)
// {
//     string str(ListKota[n].visited);
//     for (unsigned i = 0; i < str.length(); i += 3) {
//         KotaTerpendek.push_back(str.substr(i, 3));
//     }
//     for (int i = 0; i<KotaTerpendek.size()-1; i++)
//     {
//         int I1 = Search(KotaTerpendek[i]);
//         int I2 = Search(KotaTerpendek[i+1]);

//         float x1 = ListKota[I1].x*20;
//         float y1 = getmaxy()-ListKota[I1].y*20;
//         float x2 = ListKota[I2].x*20;
//         float y2 = getmaxy()-ListKota[I2].y*20;

//         setcolor(YELLOW);
//         setlinestyle(0, 0, 3);
//         line(x1,y1,x2,y2);
//         setlinestyle(0, 0, 2);
//         setcolor(WHITE);
//     }
// }

// int main()
// {
//     int pilihan,inNum;
//     string nama,nama2;
//     float x,y;

//     Append("BGR", 9, 2);
//     Append("JKT", 15, 10);
//     Append("SBY", 9, 18);
//     Append("BDG", 5, 8);
//     Append("TGR", 4, 15);

//     Connect("BGR","JKT");
//     Connect("BGR","BDG");
//     Connect("BDG","SBY");
//     Connect("TGR","BDG");
//     Connect("JKT","SBY");
//     Connect("TGR","JKT");

//     initwindow(400,400);
//     MenuAwal:
//     cleardevice();
//     Draw();
//     cout << "LIST KOTA" << endl;
//     cout << "=======================================================\n";
//     cout << "| No |       Nama Kota       |  x  |  y  |    Next    |\n";
//     cout << "=======================================================\n";
//     for(int i=0;i < ListKota.size();i++){
//         cout << "| "<< setiosflags(ios::left) <<setw(3) <<i+1<<"|";
//         cout << " " << setiosflags(ios::left) <<setw(22)<<ListKota[i].NamaKota<<"|";
//         cout << " " << setiosflags(ios::left) <<setw(4) <<ListKota[i].x<<"|";
//         cout << " " << setiosflags(ios::left) <<setw(4) <<ListKota[i].y<<"|";
//         int jumlahNext = ListKota[i].Next.size();
//         if( jumlahNext == 0){
//             cout << " " << setiosflags(ios::left)<<setw(11)<<" ";
//         }
//         else{
//             for(int j = 0;  j<jumlahNext ;j++){
//                 cout << " " << setiosflags(ios::left)<<setw(11/jumlahNext)<<Search(ListKota[i].Next[j].NamaNext)+1;
//             }
//         }
//         if(i<ListKota.size()-1) cout<<"|\n-------------------------------------------------------\n";
//         else                    cout<<"|\n=======================================================\n";
//     }
//     cout << "========MENU========" << endl;
//     cout << "1. Tambah Kota Baru" << endl;
//     cout << "2. Hapus Kota" << endl;
//     cout << "3. Hubungkan Kota" << endl;
//     cout << "4. Hubungkan Otomatis"  << endl;
//     cout << "5. Algoritma Dijkstra" << endl;
//     do{
//         cout << "Pilih: ";
//         cin >> pilihan;

//         if(pilihan == 1){
//             cout << ">>Masukkan Nama Kota dan Koordinat" << endl;
//             cout << "Nama kota: ";
//             cin >> nama;
//             cout << "Koordinat[x y]: ";
//             cin >> x >> y;
//             Append(nama,x,y);

//             system("CLS");
//             goto MenuAwal;
//         }
//         if(pilihan == 2){
//             cout << ">>Masukkan Nama Kota yang Ingin Dihapus" << endl;
//             cout << "Nama kota: ";
//             cin >> nama;
//             int terhapus = Search(nama);
//             for(int i = 0; i < ListKota.size(); i++){
//                 for(int j = 0; j < ListKota[i].Next.size(); j++){
//                     if(ListKota[i].Next[j].NamaNext == nama) ListKota[i].Next.erase(ListKota[i].Next.begin()+j);
//                 }
//             }
//             ListKota.erase(ListKota.begin() + terhapus);

//             system("CLS");
//             goto MenuAwal;
//         }
//         if(pilihan == 3){
//             cout << ">>Masukkan Nama Kota yang Ingin Dihubungkan" << endl;
//             cout << "Kota Pertama: ";
//             cin >> nama;
//             cout << "Kota Kedua: ";
//             cin >> nama2;
//             Connect(nama,nama2);

//             system("CLS");
//             goto MenuAwal;
//         }
//         if(pilihan == 4){
//             cleardevice();
//             int flag = 0;
//             float xn,yn;
//             int page=0;
//             while(1){
//                 setactivepage(page);
//                 setvisualpage(1-page);
//                 cleardevice();

//                 Draw();
//                 float xh = mousex();
//                 float yh = mousey();
//                 setfillstyle(SOLID_FILL,WHITE);
//                 for(int i=0; i<ListKota.size(); i++){
//                     float x1 = ListKota[i].x*20;
//                     float y1 = getmaxy()-ListKota[i].y*20;
//                     if(xh<x1+10 && xh>x1-10 && yh<y1+10 && yh>y1-10){
//                         floodfill(x1,y1,WHITE);
//                         if(ismouseclick(WM_LBUTTONDOWN))
//                         {
//                             clearmouseclick(WM_LBUTTONDOWN);
//                             setactivepage(0);
//                             setvisualpage(0);
//                             xn = x1;
//                             yn = y1;
//                             flag++;
//                             if(flag == 1) nama = ListKota[i].NamaKota;
//                             if(flag == 2) {
//                                 nama2 = ListKota[i].NamaKota;
//                                 Connect(nama,nama2);
//                                 break;
//                             }
//                         }
//                     }
//                 }
//                 if(flag != 0) floodfill(xn,yn,WHITE);
//                 if(flag == 2) break;
//                 delay(15);
//                 page = 1-page;
//             }
//             system("CLS");
//             goto MenuAwal;
//         }
//         if(pilihan == 5){
//             cout << ">>Masukkan Nama Kota yang Ingin Dicari Jarak Terpendeknya" << endl;
//             cout << "Kota Pertama: ";
//             cin >> nama;
//             cout << "Kota Kedua: ";
//             cin >> nama2;
//             initDjikstra();
//             Dijkstra(nama,nama2,0,nama);
//             visualisasiDijkstra(Search(nama2));
//             cout << "TOTAL JARAK TERPENDEK: "<< ListKota[Search(nama2)].TK<<endl;
//             for(int i=0; i<KotaTerpendek.size(); i++){
//                 cout<<KotaTerpendek[i]<<endl;
//             }
//             cout << "Enter any value to continue...";
//             cin >> nama2;
//             system("CLS");
//             goto MenuAwal;
//         }

//     }while(pilihan < 6);


//     return 0;
// }