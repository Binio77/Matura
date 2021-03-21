#include<iostream>
#include<fstream>
#include<climits>
#include<map>
#include<cmath>

using namespace std;

int main()
{
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("zadanie4odmarcyna.txt");

    int tab[1000];

    for(int i=0; i<1000; i++)
        f_wej >> tab[i];

    map <long, int> myMap;
    for(int i=0; i<1000; i++)
    {
        myMap[fabs(tab[i-1] - tab[i])]++;
    }
    for(auto e: myMap)
    {
        cout << e.first << ' ' <<  e.second<<endl;
    }
    //na podstawie tych coutow widze ze ostatni wyswietlany to najw luka, a pierwszy to najm4,1, 
    //a na podstawie wartosci moge stwierdzic jakie sa najczesciej wystepujace luki4,3
    getchar();
    getchar();
    return 0;
}