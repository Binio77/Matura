#include<iostream>
#include<fstream>
#include<climits>
#include<vector>

using namespace std;

int main()
{
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("zadanie4,2.txt");
    long int tab[1000], roznica;
    bool restart = true;
    vector <int> aCiag;
    vector <int> najCiag;

    for(int i=0; i<1000; i++)
        f_wej >> tab[i];


    roznica = abs(tab[0] - tab[1]);
    aCiag.push_back(tab[0]);

    for(int i=2; i<1000; i++)
    {
        long int sRoznica = roznica;
        roznica = abs(tab[i] - tab[i-1]);

        if(restart)
            sRoznica = roznica;

        if(roznica == sRoznica)
        {
            aCiag.push_back(tab[i]);
            restart = false;
        }
        else
        {
            if(aCiag.size() > najCiag.size())
                najCiag = aCiag;

            aCiag.clear();

            restart = true;

            aCiag.push_back(tab[i]);
        }
    }
    f_wyj << najCiag.size() << ' ' << najCiag[0] << ' ' << najCiag[najCiag.size()-1];
    

    getchar();
    getchar();
    return 0;   
}