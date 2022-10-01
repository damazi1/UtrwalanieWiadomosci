#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{
    //stowrzenie zmiennych
    string slowo;
	string wpis;
    int pom=1;
	int nrlinii=0;
	int powt=0;
    bool spr = false;


    // Wczytanie pliku
    ifstream plik;
    ofstream zapis;
    plik.open ("tekst.txt");
    zapis.open ("wielkie.txt");

    // Sprawdzenie pliku tekstowego
    if (plik.is_open()) cout<<"Pomyslne zaladowanie pliku\n\nWcisnij dowolny klawisz aby wyswietlic zawartosc"; // Plik zaladowany
    else { cout<<"Blad wczytania pliku\n"; //Blad wczytania
    return 0;
    }
	
    //Dowod otwarcia pliku
    while (plik >> slowo) //Zapisuje slowa dopoki takie jeszcze s�
    {
        cout<<" "<<slowo<<", "; //wyswietlenie slow

        if(pom%7==0) //podzial slow na 7 kolumn dla estetyki
            cout<<endl;
        pom++;

        if(isupper(slowo[0])) //sprawdzenie czy pierwsza litera jest wielka a nastepnie zapisuje ja do wielkie.txt
            zapis<<slowo<<endl;

    }

    zapis.close();
     plik.close ();

     string tablica[pom];




    cout<<endl<<endl<<"Wyrazy zostaly wyswietlone oraz te zaczynajace sie z duzej litery zapisane, wcisnij dowolny przycisk aby kontynuowac\n\n";

    cout<<"Jakie slowo chcesz znalezc?\n";
    cin>>wpis;

   plik.open ("tekst.txt");
       if (!plik.is_open())
    { cout<<"Blad wczytania pliku\n";
    return 0;
    }
   while(plik >> slowo) // kolejne wczytanie slow do sprawdzenia czy slowo znajduje sie w pliku
   {
       if(slowo==wpis)
       {
           cout<<"\nznalezione w linii "<<nrlinii+1; //pokazuje linie gdzie slowo zostalo znalezione, linia posiada +1 poniewaz jest numeracja od 0
           spr=true; // przypisanie bool true, ze slowo zostalo znalezione
       }
       nrlinii++;
   }

   plik.close();
  
    if(spr==false) //sprawdzenie boola, czy slowo zostalo znalezione
        cout<<"\nnie ma";

        cout<<"\n\nWcisnij dowolny klawisz";
        cout<<"Ile powtorzen jest w pliku?\n"; //sprawdzenie powtorzen w pliku

        spr=false;
        plik.open("tekst.txt");
            if (!plik.is_open())
    { cout<<"Blad wczytania pliku\n";
    return 0;
    }
        nrlinii=0;


        for(int i=0;i<pom-1;i++) //zapis z pliku do tablicy
            plik>>tablica[i];

        for(int i=0;i<pom-1;i++) //sprawdzanie jedno slowo po drugim powtorzen w pliku
        {
            if(tablica[i]==tablica[i+1])
            {
                spr=true;
                powt++;
            }
        }
        if(spr==true) cout<<"\nPowtorzone zostalo "<<powt<<" razy\n";
        else cout<<"\nNie ma powtorzen\n";
        plik.close();

    return 0;
}
