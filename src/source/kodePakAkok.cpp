#include <iostream>
#include<vector>

using namespace std;
struct tKotaNext
{
    string sKotaNext;
    float jarak;
};
struct tKota
{
    float TK;
    string sNamaKota;
    vector<struct tKotaNext> lKotaNext;
};


vector<tKota> lKota;

void Append(string sNamaKota)
{
    struct tKota d;
    d.TK=100000000000;
    d.sNamaKota =sNamaKota;
    lKota.push_back(d);
}
int CariIndeksKota(string sNamaKota)
{
    int ikota = -1;
    for (int i = 0; i<lKota.size();i++)
    {
        string s =lKota[i].sNamaKota;
        if (sNamaKota.compare(s)==0)
        {
            ikota = i;
            break;
        }

    }
    return ikota;
}
bool  Hubung(string sDari, string sKe, float Jarak)
{
    int n1,n2;
    n1= CariIndeksKota(sDari);
    n2 = CariIndeksKota(sKe);
    bool bKetemu = true ;
    if ((n1>=0)&&(n2>=0))
    {
        struct tKotaNext d;
        d.sKotaNext =sKe;
        d.jarak = Jarak;
        lKota[n1].lKotaNext.push_back(d);

    }else
    {
        bKetemu = false;
    }
    return bKetemu;
}

void Cetak(string sKota,string s)
{
    int n = CariIndeksKota(sKota);
    s=s+sKota;
    cout<< s<<endl;
    for (int i =0;i<lKota[n].lKotaNext.size();i++)
    {
         string sNext = lKota[n].lKotaNext[i].sKotaNext;
         float jarak = lKota[n].lKotaNext[i].jarak;


      Cetak(sNext,s);

    }
}

void djikstra1(string sKota,float TK)
{
    //Skotak = G, TK = 0
    int n=CariIndeksKota(sKota);
    if (TK > lKota[n].TK)
    {
        return;
    }
    lKota[n].TK = TK ;//0
    //C E Jumlah Terhubung 2
    for (int i  = 0; i<lKota[n].lKotaNext.size();i++)
    {
        //index i =0 snext C
        string snext = lKota[n].lKotaNext[i].sKotaNext;
        //index i=0 jarak = jarak dari G ke C->10
        float jarak= lKota[n].lKotaNext[i].jarak;
        //index i=0 Tinkat Kedekatan =0
        // index i = 0  sNext = C
        // Tk+jarak = 0+ 10
        djikstra2(snext,TK+jarak);
    }
}


void djikstra2(string sKota,float TK)
{
    //Skota = C, TK = 10
    
    int n=CariIndeksKota(sKota);
    //lKota[n].TK=1000
    
    if (TK > lKota[n].TK)
    {
        return;
    }
    //lKota[n].TK=10
    lKota[n].TK = TK ;
    //snext -> G dan A
    for (int i  = 0; i<lKota[n].lKotaNext.size();i++)
    {
        //i=0  snext =G, Jarak C ke  G =10
        //i=1 snext =A Jarak C ke A =10
        string snext = lKota[n].lKotaNext[i].sKotaNext;
        // i = 0 Jarak =10
        // i=1  jarak =10
        float jarak= lKota[n].lKotaNext[i].jarak;
        // i 0 -> TK = 10 ,TK+jarak = 20
        // i = 1->TK =10 ,TK+jarak =20
        djikstra3(snext,TK+jarak);
    }
}


void djikstra3(string sKota,float TK)
{
    //1. Skota = G, TK = 20
    //2. Skota = A,TK = 20
    
    int n=CariIndeksKota(sKota);
    //1. lKota[n].TK=0
    //2. lKota[n].TK=10000
    
    if (TK > lKota[n].TK)
    {
        return;
    }
    //1. lKota[n].TK=10
    //2. lKota[n].TK=20
    
    lKota[n].TK = TK ;
    //1. snext -> G dan A
    //2. snext -> c dan B 
    for (int i  = 0; i<lKota[n].lKotaNext.size();i++)
    {
        //1.  i=0  snext =G, Jarak C ke  G =10
        //2.  i=0   snext  C, Jarak A ke C =10 
        //2. i = 1 snext =B, jarak A ke B = 1
        string snext = lKota[n].lKotaNext[i].sKotaNext;
        //1.  i = 0 Jarak =10
        //2.  i= 0  jarak =10 
        //2.  i = 1 Jarak  = 1
        float jarak= lKota[n].lKotaNext[i].jarak;
        //1.  i= 0 -> TK = 10 ,TK+jarak = 20
        //2.  i= 0 -> TK = 20  ,TK+jarak = 10+20=30
        //2. i = 1->TK =20 , TK+Jarak = 20+1 =21 
        djikstra4(snext,TK+jarak);
    }
}




void djikstra4(string sKota,float TK)
{
    //1. sKota = C TK 30
    //2. sKota = B, TK =21 
    
    int n=CariIndeksKota(sKota);
    //1. lKota[n].TK=10
    //2. lKota[n].TK = 1000
    
    if (TK > lKota[n].TK)
    {
        return;
    }
    
    lKota[n].TK = TK ;
    for (int i  = 0; i<lKota[n].lKotaNext.size();i++)
    {
        string snext = lKota[n].lKotaNext[i].sKotaNext;
        float jarak= lKota[n].lKotaNext[i].jarak;
        
        // djikstra5(snext,TK+jarak);
    }
}






void djikstra(string sKota,float TK)
{
    
    int n=CariIndeksKota(sKota);
    
    if (TK > lKota[n].TK)
    {
        return;
    }
    
    lKota[n].TK = TK ;
    for (int i  = 0; i<lKota[n].lKotaNext.size();i++)
    {
        string snext = lKota[n].lKotaNext[i].sKotaNext;
        float jarak= lKota[n].lKotaNext[i].jarak;
        djikstra(snext,TK+jarak);
    }
}




int main()
{
    Append("A");
    Append("B");
    Append("C");
    Append("D");
    Append("E");
    Append("F");
    Append("G");
    Append("H");

    bool b;
    b = Hubung("A","B",1);
    b = Hubung("B","A",1);

    b = Hubung("A","C",3);
    b = Hubung("C","A",3);



    b = Hubung("B","D",3);
    b = Hubung("D","B",3);

    b = Hubung("B","E",3);
    b = Hubung("E","B",3);

    b = Hubung("C","F",1);
    b = Hubung("F","C",1);

    b = Hubung("C","G",2);
    b = Hubung("G","C",2);

   //Cetak("A","");
   djikstra1("G",0);
   for (int i =0; i<lKota.size();i++)
   {
       cout <<lKota[i].sNamaKota<<" Jarak Ke E "<< lKota[i].TK<<endl;
   }
    return 0;
}