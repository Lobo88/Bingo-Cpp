#include <iostream>
#include <deque>
#include <time.h>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <functional>

int iloscKup;
int pulaLiczb=21;
int iloscWszystkichLicz=30;

using namespace std;

struct Highscore
{
    string name;
    int total;
    int rank;
};
 Highscore a[5];

bool compareTwoHighscore(Highscore a, Highscore b)
{
    if (a.total != b.total )
        return a.total > b.total;

}


void computeRanks(Highscore a[], int hiScoreTab)
{

    sort(a, a+5, compareTwoHighscore);

    for (int i=0; i<hiScoreTab; i++)
        a[i].rank = i+1;
}
void dodajDOwynikow(int punkty){

string imie;

if(punkty>a[4].total){
        cout<<"\n"<<"Podaj imie ";
cin>>imie;
    a[4].name = imie ;
    a[4].total = punkty ;
    }
else{
        system ("cls");
cout<<"Twoj wynik :"<<punkty;
cout<<"\n"<<"Masz za malo punktow by sie dostac na liste"<<"\n";}
}

template <typename tablica>

int &Losuj(tablica& wylosowaneGry,int iloscLiczb){

for(int z=0; z<iloscKup; z++){
   for(int i=0; i<iloscLiczb; i++){

        wylosowaneGry[z][i]=rand()%iloscWszystkichLicz+1;

   for(int j=0; j<i; j++){
        while(wylosowaneGry[z][j]==wylosowaneGry[z][i])
        {
            wylosowaneGry[z][i]=rand()%iloscWszystkichLicz+1;
            j= -1;
        }
        }//cout<<wylosowaneGry[z][i];
   }
}cout<<endl;
cout<<"wylosowane Twoje liczby:"<<endl;
for(int k=0; k<iloscKup; k++){
        for(int l=0; l<iloscLiczb; l++){
cout<<wylosowaneGry[k][l]<<",";
}
cout<<endl;

    }
}

 int Automat(int *kupony,int *ileCyfr){
     bool done=false;

  while (!done){
do{
 cout<<"Podaj ile chcesz miec wylosowanych cyfr (max20): ";
 cin>>*ileCyfr;
if(*ileCyfr>20){done=true;}
else{done=false;}
  }while(done);

 cout<<"Na ile kuponow chcesz grac(max5):";
 cin>>*kupony;
 if(*kupony>=6 && *kupony <=0){

done=true;
  }
else if(*kupony>0 && *kupony <6){return *kupony,*ileCyfr;}

  };done=false;

 }

int  *wypelnijTablice( int tab[] )
{
  for (int i=0; i<iloscWszystkichLicz; i++)
    {
        tab[i]=rand()%iloscWszystkichLicz+1;

        for (int j=0; j<i; j++) // porównuje z poprzednimi
        {
            while (tab[j]==tab[i]) // dopóki sie powtarza losuj jeszcze raz
            {
                tab[i]=rand()%iloscWszystkichLicz+1;
                j = -1;
            }
        }
    }

};

 int wpiszLiczbe(){
     int x;
 try
    {
        if (!(cin>> x))
    throw -1;
    }
catch(  int)
    {
      cout << "Miales wybrac opcje (liczbe)" << '\n';
      throw invalid_argument( "Zlapano nieznany wyjatek" );
      cin.clear();

    }return x;
}

int startAutoGry(deque<int>&liczby){

cout<<"zaczynamy losowanie: "<<endl;
cin.get();
int x;
cout<<"wylosowana liczba: ("<<liczby.back()<<")";
x=liczby.back();
liczby.pop_back();
//cout<<liczby.back()<<"koniec auto ";
cout<<endl;
return x;

}

int main()
{
    srand(time(NULL));
    int tab[pulaLiczb];
    int wypisz;




a[0].name = "Bryan" ;
    a[0].total = 80 ;


    a[1].name= "Kevin" ;
    a[1].total= 95 ;

    a[2].name = "Nick" ;
    a[2].total = 95 ;



    a[3].name = "AJ" ;
    a[3].total = 80 ;



    a[4].name = "Howie" ;
    a[4].total = 80 ;

    a[4].name = "tom" ;
    a[4].total = 100 ;

    for(int i = 0; i < iloscWszystkichLicz; i++){
           tab[i] = i;
    wypelnijTablice(tab);}

       for (int i=0; i<pulaLiczb; i++)
    {
       // cout << tab[i] << endl;
    }




    //cout <<"ostani element kontenera"<<* it << endl;



    //for( int i = 0; i < liczby.size(); i++ ){
    // cout<<liczby[i]<<",";}
bool loop = true;
 while (wypisz!=1 && wypisz!=2){
 cout<<"Gra w bingo"<<endl;
 cout<<"1.Gra w trybie automatycznym."<<endl;
 cout<<"2.Tabela wynikow"<<endl;

    deque < int > liczby;
    deque < int >::iterator it;

    for( int i = 0; i < iloscWszystkichLicz; i++ ) it = liczby.insert( liczby.end()
        , tab[i]);
wypisz=wpiszLiczbe();



 switch( wypisz )
{
case 1:{
    cout<<"Wybrales gre w trybie automatycznym."<<endl<<endl;
    int punkty=0;
    int iloscLiczb=0;
    const int kup=5;
    const int licz=20;
    Automat(&iloscKup,&iloscLiczb);
    cout<<"posiadasz "<<iloscKup<<" kuponow, wybranych po "<<iloscLiczb<<" liczby"<<endl<<endl;
    int wylosowaneGry[kup][licz];
    int drugaTablica[iloscKup][iloscLiczb+1]={};
    Losuj(wylosowaneGry,iloscLiczb);

    int sizer=1;
        while(liczby.size()>0){
            int losowa=startAutoGry(liczby);

            for(int n=0; n<iloscKup; n++){

                for(int m=0; m<iloscLiczb; m++){

                 if(wylosowaneGry[n][m]==losowa){
                    cout<<"("<<wylosowaneGry[n][m]<<"),";
                    drugaTablica[n][m]=1;
                    drugaTablica[n][iloscLiczb]+=1;
                    punkty+=10;

                 }
                 else{cout<<wylosowaneGry[n][m]<<",";}

                }cout<<endl;


            if(drugaTablica[n][iloscLiczb]==iloscLiczb){cout<<"kupon nr:"<<n+1<<"Bingo!!!!"<<endl;
            punkty-=n;
            }
           }
            }


    //cout<<"pozostalo w tablicy "<<liczby.size();
    cout<<endl;
   // for(int t=0; t<iloscKup; t++){
   // for(int n=0; n<iloscLiczb+1; n++){
    //cout<<drugaTablica[t][n]<<",";
    //}cout<<endl;}
    cout<<"punkty:"<<punkty;
    dodajDOwynikow(punkty);
     wypisz=3;
break;
}
case 2:{

    cout<<"Tabela wynikow."<<endl<<endl;
     computeRanks(a, 5);
       cout << "Rank" <<"\t" << "Name" << "\t";
    cout <<"Total"<<endl;

    for (int i=0; i<5; i++)
    {
        cout << a[i].rank << "\t";
        cout << a[i].name << "\t";
        cout << a[i].total <<"\t";
        cout <<"\n";

    }

wypisz=3;
break;
}

}
};

 cin.get();
    return 0;
}
