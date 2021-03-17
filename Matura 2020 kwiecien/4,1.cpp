#include<iostream>
#include<fstream>
#include<climits>

using namespace std;

int main()
{
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("zadanie4,1.txt");
    int tab[1000], najwR = INT_MIN, najmR = INT_MAX;
    for(int i=0; i<1000; i++)
        f_wej >> tab[i];

    for(int i=0; i<999; i++)
    {
        int roznica = abs(tab[i] - tab[i+1]);
        if(roznica > najwR) 
            najwR = roznica;

        if(roznica < najmR) 
            najmR = roznica;
    }

    f_wyj << najwR << endl <<najmR;

    getchar();
    getchar();
    return 0;
}