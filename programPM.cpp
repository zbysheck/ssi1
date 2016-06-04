//program demonstracyjny,

//na pocz¹tku programu za³¹czamy biblioteki i pliki naglowkowe ze zdefiniowanymi funkcjami
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
//Pliki z rozszerzeniem .h zawieraja tylko prototypy funkcji, kody znajduja
//sie w plikach o tych samych nazwach lecz z rozszerzeniem .cpp
#include "matrix.h"

//deklarujemy u¿ywanie przestrzeni nazw std, zawieraj¹cej wiele przydatnych komend,
//je¿eli nie zdeklarowalibyœmy przestrzeni nazw std, przed komendami tej przestrzeni nale¿a³oby u¿yæ zapisu std::
// np. std::cout<<"tekst";         
using namespace std;

/*
string nazwap="diabetes.txt";
int wym2=num_rows_file(nazwap.c_str());
int wym1=num_cols_file(nazwap.c_str());

string **G;
double MAX(int numarg){
    double max=string_to_double(G[1][numarg]);
    for(int i=1;i<=wym2;i++){
        if (max<string_to_double(G[i][numarg]) ) max= string_to_double(G[i][numarg]);
    };
    return max;
};
double MIN(int numarg){
    double min=string_to_double(G[1][numarg]);
    for(int i=1;i<=wym2;i++){
        if (min>string_to_double(G[i][numarg]) ) min= string_to_double(G[i][numarg]);
    };
    return min;
};
*/


//w funkcji main mamy nasz g³ówny program,
int main (void) {
cout<<"Przykladowy program ver. 1.01\n";

//definiujemy nazwe pliku, musi istnieæ w katalogu programu
string nazwap="diabetes.txt";

//string **attr_type2;
//korzystamy z funkcji umieszczonych w pliku matrix.h
// w celu znalezienia rozmiaru wczytywanego pliku,
//plik powinien byc w formacie
//6 2 5 6 1
//5 8 9 2 0
int wym2=num_rows_file(nazwap.c_str());
int wym1=num_cols_file(nazwap.c_str());

//teraz deklarujemy dynamicznie tablice do, której wczytamy nasz plik,
int rows = wym2+1;
std::string **G;
G = new std::string*[rows];
while(rows--) G[rows] = new std::string[wym1+1];

////wczytujemy tablice w postaci string, czyli jej elementy traktujemy jako stringi(ci¹gi znaków)
//wym2 to liczba wierszy
//wym1 to liczba kolumn
//G nasza tablica stringów
//nazwap.c_str() podajemy nazwe wczytywanego pliku w odpowiednim formacie do funkcji.
cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwap;
getchar();
wczytywanie(wym2,wym1,G,nazwap.c_str());
//wypisujemy wczytan¹ tablicê na ekran
cout<<"\nWypisujemy na ekran wczytana tablice\n\n";
for(int i=0;i<wym2+1;i++)
 {
 for(int j=0;j<wym1+1;j++)
  {
  cout<<" "<<G[i][j];
  }
  cout<<"\n";
 }
 
cout<<"\n\nNacisnij ENTER aby wykonac przykladowe operacje na elementach wczytanego pliku";
getchar();
int temp1,temp2;
int wynik;
double wynik2;

temp1=string_to_int(G[1][1]);
temp2=string_to_int(G[1][2]);
wynik=temp1+temp2;

//wyswietlamy wynik
//cout<<"wartosci z tablicy G[1][1],G[1][2] \n"<<temp1<<" + "<<temp2<<" = "<<wynik <<"\n";
cout<<"\n"<<"Klasa decyzyjna (ostatnie miejsce w tablicy): "<<G[1][9] <<"\n";


map<string, int> classcounts;
for(int i=1;i<=wym2;i++){
//    cout<<" "<<G[i][wym1]<<" ";
    ++classcounts[G[i][wym1]];
};
cout<< endl;

map<string, int>::iterator it;
cout <<"Klasy decyzyjne: "<<endl;
for (it=classcounts.begin(); it!=classcounts.end(); ++it){
    cout << it->first <<" ";
};



double klasa0=0;
double klasa1=0;
for (int i=1;i<=wym2;i++){
    
  if (string_to_double(G[i][9]) == 0) klasa0++;
  if (string_to_double(G[i][9])== 1) klasa1++;   
  
}
cout<<"\n"<<"Ilosc obiektow w klasie pierwszej "<<klasa0<<"\n";
cout<<"\n"<<"Ilosc obiektow w klasie drugiej "<<klasa1<<"\n";

int il=0;
for (int i=1;i<=wym2;i++){
    il++;
}
cout<<"laczna ilosc obiektow: "<<il<<"\n";

/*

for(int c=1;c<wym1;c++){
        
int numer_argumentu        
double max=string_to_double(G[1][numer_argumentu]);
double min=string_to_double(G[1][numer_argumentu]);      
            
for(int i=1;i<=wym2;i++){
if (max<string_to_double(G[i][numarg]) ) max= string_to_double(G[i][numarg]);
};
return max;
};      
        cout <<"Wartosc maksymalna "<< MAX(c)<< endl;
        cout <<"Wartosc minimalna "<< MIN(c)<< endl;
        //for(int i=1;i<=wym2;i++){
        //    cout << G[i][c]<<" ";     
        cout<<endl;
    };
};
*/

int tab[wym2+1];
int najwiekszy;
int najmniejszy;

for( int j=1; j<wym1;j++){

najwiekszy=0;
najmniejszy=10000;

for( int i=1; i<=wym2;i++){
     int temp3 = string_to_int(G[i][j]);
     int temp4 = string_to_int(G[i][j]);
if( temp3 > najwiekszy )
    najwiekszy = temp3;
    
if(temp4 < najmniejszy )
          najmniejszy = temp4;
}
cout<<"Atrybut: "<<j<<" max: "<<najwiekszy<<"\n";
cout<<"Atrybut: "<<j<<" min: "<<najmniejszy<<"\n";
}

//ilosc roznych atrybutow
map<string, int> latrybutow;
for(int i=1;i<wym1;i++){
    latrybutow.clear();
    for(int j=1;j<=wym2;j++){
            ++latrybutow[G[j][i]];
    };
    cout << "Ilosc wartosci atrybutu"<<i<<": "<<latrybutow.size()<<endl;
};



//lista roznych wartosci dla atrybutow
for(int i=1;i<wym1;i++){
    latrybutow.clear();
    for(int j=1;j<=wym2;j++){
            ++latrybutow[ G[j][i] ];
    };
    cout << "Mozliwe wartosci dla atrybutu"<<i<<": ";
    for (it=latrybutow.begin(); it!=latrybutow.end(); ++it){
        cout << it->first <<" ";
    };
    cout <<endl;
};


double srednia;

//srednia i odchylenie
for( int j=1; j<wym1;j++){
srednia =0.00;

for( int i=1; i<=wym2;i++){
     double temp5 = string_to_double(G[i][j]);
     srednia = srednia + temp5;
     
}
srednia = srednia / wym2 ; 
cout<<"\n srednia dla: "<<j<<"= "<<srednia<<"\n";
};

//double srednia2;
//double odchylenie;
//double wariancja;


for( int j=1; j<wym1;j++){
double srednia2 =0.00;
double wariancja =0.00;
double odchylenie =0.00;
double temp6=0.00;

for( int i=1; i<=wym2;i++){
     double temp5 = string_to_double(G[i][j]);
     srednia = srednia + temp5;
     
	 temp6+= (i-srednia)*(i-srednia);
}

srednia = srednia / wym2 ; 
wariancja= temp6/wym2;
odchylenie = sqrt(wariancja);

cout<<"\n srednia dla: "<<j<<"= "<<srednia<<"\n";
cout<<"\n wariancja dla: "<<j<<"= "<<wariancja<<"\n";
cout<<"\n odchylenie dla: "<<j<<"= "<<odchylenie<<"\n";
};


string nazwa2="diabetes-type.txt";

rows = wym2+1;
string **attr_type;
attr_type = new string*[rows];
while(rows--) attr_type[rows] = new string[3];

cout<<"\n\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwa2;
getchar();
wczytywanie(wym2,2,attr_type,nazwa2.c_str());

cout<<"\nWypisujemy na ekran tablice attr_type\n\n";
for(int i=1;i<wym1;i++)
 {for(int j=1;j<3;j++){cout<<" "<<attr_type[i][j];}cout<<"\n";}








//cout<<"\n\nPrzykladowa konwersja ze string na double:";
//cout<<"\nWartosc G[1][1] jako string = "<<G[1][1];
//cout<<"\nWartosc G[1][1] jako double = "<<string_to_double(G[1][1]);

cout<<"\n\nNacisnij ENTER aby zakonczyc";
getchar();

return 0;
}


// wielkosci klas decyzyjnych . chodzi o to, ze na koncu kazdego wiersza z danymi
//s¹ 0 lub 1 . czyli s¹ dwie klasy decyzyjne. i trzeba zliczyc liczbe obiektów w 
//ka¿dej z klas . 
