#include <iostream>
#include <list>
#include <windows.h>
#include<string>
#include<fstream>
using namespace std;

list <int> lista; //utworzenie listy z podstawowy typem danych int
int choice,ile,a;

void wyswietl()
{
    ofstream zapis("lista_dwukierunkowa.txt");
    cout<<endl;
    cout<<" Lista: "<<endl;
    cout<<"____________________________"<<endl;

    for(list<int>::iterator i=lista.begin(); i!= lista.end(); ++i) //funkcja do wyswietlania listy i zapisywania do pliku
    {
        cout<<*i<<" ";
        zapis<<*i<<" ";

    }


    cout<<endl;
    cout<<"____________________________"<<endl<<endl;
    zapis.close();
}
void push_front()
{
    int liczba;
    cout<<"Podaj ile liczb chcesz dodac: ";
    cin>>ile;
    for(int i=0;i<ile;i++){
        cout<<"Podaj jaka liczbe wstawic na poczatek listy: "; //funkcja dodajaca element na poczatek listy
        cin>>liczba;
        lista.push_front(liczba);
    }

    wyswietl();
}

void push_back()
{
    int liczba;
    cout<<"Podaj ile liczb chcesz dodac: ";
    cin>>ile;
    for(int i=0;i<ile;i++)
        {
        cout<<"Podaj jaka liczbe wstawic na koniec listy: "; //funkcja dodajaca element na koniec listy
        cin>>liczba;
        lista.push_back(liczba);
        }
    wyswietl();
}
void pop_front()
{
    cout<<"Podaj ile liczb chcesz usunac z poczatku listy: ";
    cin>>ile;
    for(int i=0;i<ile;i++)                                       //funkcja usuwajaca pierwszy element listy
    {
      lista.pop_front();
    }

    cout<<"Usunieto pierwszy element/elementy listy";
    wyswietl();
}
void pop_back()
{
    cout<<"Podaj ile liczb chcesz usunac z konca listy: ";
    cin>>ile;
    for(int i=0;i<ile;i++)                                      //funkcja usuwajaca ostatni element listy
    {
      lista.pop_back();
    }
    cout<<"Usunieto ostatni element/element listy";
    wyswietl();
}
void size()
{
    cout<<"Rozmiar listy(ile jest liczb w liscie): "<<lista.size()<<endl;     //funkcja zwracajaca rozmiar listy
    wyswietl();
}
void clear()
{
    cout<<"Wyczyszczona lista";
    lista.clear();                  //funkcja czyszczaca liste
    wyswietl();
}
void unique()
{
    cout<<"Usunieto duplikaty z listy";
    lista.unique();                     //funkcja usuwajaca duplikaty z listy
    wyswietl();
}
void remove()
{
    int liczba;
    cout<<"Usun z listy wszystkie liczby rowne: ";
    cin>>liczba;                                        //funkcja usuwajaca konkretne liczby z listy
    lista.remove(liczba);
    wyswietl();
}
void sort()
{
    cout<<"Posortowano liste rosnaco";
    lista.sort();                                      //funkcja sortujaca liste rosnaco
    wyswietl();
}
void sortmal()
{
    cout<<"Posortowano liste malejaco";
    lista.sort();
    lista.reverse();                                //funkcja sortujaca liste malejaco
    wyswietl();
}
void reverse()
{
    cout<<"Lista o odwroconej kolejnosci!";
    lista.reverse();                                //funkcja odwracajaca liste
    wyswietl();
}
void czyjest()
{
   int szukana, licznik=0;
   bool jest=false;
   cout << "Podaj liczbe: ";
   cin >> szukana;
   cout << "Pozycja: ";
   for( list<int>::iterator i=lista.begin(); i!= lista.end(); ++i ) //funkcja sprawdzajaca pozycje zadanej liczby
   {
       licznik++;
       if(*i == szukana)
       {
        jest=true;
        cout << licznik<<" ";
       }
   }
   if(jest==false)
    {
        cout<<"Nie ma podanej liczby w tablicy"<<endl;
    }
   cout<<endl<<endl;
    wyswietl();
}
void ilejest()
{
    int szukana, licznik=0;
    bool jest=false;
    cout << "Podaj liczbe: ";
    cin >> szukana;
    for( list<int>::iterator i=lista.begin(); i!= lista.end(); ++i )
       {
           if (*i == szukana)                                       //funkcja sprawdzajaca ilosc wystapien zadanej liczby
        {
            jest=true;
            licznik++;
        }

       }
       if(jest==false)
    {
        cout<<"Nie ma podanej liczby w tablicy"<<endl;
    }else
    {
    cout << "Liczba " << szukana << " wystapila: " << licznik << " razy." << endl;
    }

    wyswietl();
}

void exit()
{

    cout<<"Koniec programu!";               //wyjscie z programu

}

int main()
{
while(choice!=14)
{
cout << "1.Dodaj element/elementy na poczatek listy"<<endl;
cout << "2.Dodaj element/elementy na koniec listy"<<endl;
cout << "3.Usun pierwszy element/element listy"<<endl;
cout << "4.Usun ostatni element/element listy"<<endl;
cout << "5.Pokaz rozmiar listy"<<endl;
cout << "6.Wyczysc liste"<<endl;
cout << "7.Usun duplikaty"<<endl;                       //MENU
cout << "8.Usun wszystkie elementy rowne: "<<endl;
cout << "9.Posortuj liste rosnaco"<<endl;
cout << "10.Posortuj liste malejaco"<<endl;
cout << "11.Odwroc liste"<<endl;
cout << "12.Znajdz pozycje zadanej liczby"<<endl;
cout << "13.Policz ile razy zadana liczba wystapila w liscie"<<endl;
cout << "14.Wyjdz"<<endl;
cout << "Wybor: ";
cin >> choice;
    switch (choice)
    {
        case 1:  push_front(); break;
        case 2:  push_back();  break;
        case 3:  pop_front();  break;
        case 4:  pop_back();   break;
        case 5:  size();       break;
        case 6:  clear();      break;               //Wywolywanie funkcji za pomoca menu
        case 7:  unique();     break;
        case 8:  remove();     break;
        case 9:  sort();       break;
        case 10: sortmal();    break;
        case 11: reverse();    break;
        case 12: czyjest();    break;
        case 13: ilejest();    break;
        case 14: exit();       break;
        default:
        cout<<"Podales nie poprawna liczbe podaj liczby z zakresu 1-12!"; //zabezpieczenie przed podana zla wartoscia przez uzytkownika
        break;
    }
}
    return 0;
}
