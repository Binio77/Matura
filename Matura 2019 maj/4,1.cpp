#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

bool pow_3(int n)
{
    for(int i = 1; i <= n; i *= 3)
    {
        if(n == i)
            return true;
    }
    return false;
}

int silnia(int n)
{
    int wynik = 1;
    for(int i = 1; i <= n; i++)
    {
        wynik *= i;
    }
    return wynik;
}

int NWD(int n1, int n2)
{
    while(n1 != n2)
    {
        if(n1 >  n2)
        {
            n1 -= n2;
        }
        else
        {
            n2 -= n1;
        }
    }
    return n1;
}

int main()
{
    ifstream wej("liczby.txt");
    int liczby[500], potegi = 0;
    for(int i = 0; i < 500; i++)
    {
        wej >> liczby[i];
        if(pow_3(liczby[i]))
            potegi++;
        
        int n_liczba = liczby[i];
        int suma = 0;
        while(n_liczba > 0)
        {
            int cyfra = n_liczba % 10;
            n_liczba /= 10;
            suma += silnia(cyfra);
            
        }
        if(suma == liczby[i])
            cout << liczby[i] << endl;
    }
    cout << potegi << endl;

    //zad3

    int obecnyNWD;
    int obecnaDlugosc = 2;
    int najdluzszy = 1, pierwszaLiczba, naj_NWD;


    obecnyNWD = NWD(liczby[0], liczby[1]);

    for(int i=2; i<500; i++)
    {
        if(NWD(obecnyNWD, liczby[i]) > 1)
        {
            obecnyNWD = NWD(obecnyNWD, liczby[i]);
            obecnaDlugosc++;
        }
        else
        {
            if(obecnaDlugosc > najdluzszy)
            {
                najdluzszy = obecnaDlugosc;
                pierwszaLiczba = liczby[i-obecnaDlugosc];
                naj_NWD = obecnyNWD;
            }

            obecnaDlugosc = 2;
            obecnyNWD = liczby[i];
        }
    }

    cout << pierwszaLiczba << " " << najdluzszy << " " << naj_NWD;

    getchar();
    getchar();
    return 0;
}