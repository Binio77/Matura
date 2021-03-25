#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

bool czy_Pierwsza(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

bool palindrom(string wyraz)
{
    string wyraz2 = wyraz;
    reverse(wyraz2.begin(), wyraz2.end());
    if(wyraz == wyraz2)
    {
        return true;
    }
    else
    {
        while(wyraz[wyraz.size() -1] == '0')
            wyraz.erase(wyraz.end() -1);

        wyraz2 = wyraz;
        reverse(wyraz2.begin(), wyraz2.end());
        if(wyraz == wyraz2)
            return true;

        return false;
    }
}

string binarne(long int liczba)
{
    string wynik = "";
    while(liczba > 0)
    {
        wynik += to_string(liczba % 2);
        liczba /= 2;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

int main()
{
    
    ifstream wejscie("dane_przyklad.txt");
    long int liczby[500];
    for(int i = 0; i < 500; i++)
        wejscie >> liczby[i];
    
    vector<long int> pierwsze;
    for(int i = 0; i < 500; i++)
        if(czy_Pierwsza(liczby[i]))
            pierwsze.push_back(liczby[i]);

    cout << pierwsze.size() << ' ' << *max_element(pierwsze.begin(), pierwsze.end()) << ' ' << *min_element(pierwsze.begin(), pierwsze.end()) << endl;

    int ilosc_palindromow = 0;
    for(int i = 0; i < 500; i++)
    {
        string wyraz = binarne(liczby[i]);
        if(palindrom(wyraz))
        {
            ilosc_palindromow++;
        }
    }
    cout << ilosc_palindromow <<endl;

    int pary = 0;
    for(int i = 0; i < 500; i++)
    {
        for(int j = i + 1; j < 500; j++)
        {
            string wyraz = to_string(liczby[i]), wyraz2 = to_string(liczby[j]);
            set<char>cyfry1;
            set<char>cyfry2;

            cyfry1.insert(wyraz.begin(), wyraz.end());
            cyfry2.insert(wyraz2.begin(), wyraz2.end());

            if(cyfry1 == cyfry2)
                pary++;
        }
    }
    cout << pary;


    getchar();
    getchar();
    return 0;
}