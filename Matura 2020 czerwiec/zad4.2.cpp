#include<iostream>
#include<utility>
#include<fstream>
#include<vector>
#include<climits>
#include<string>

using namespace std;

bool Pierwsze(int n)
{
    for(int i=2; i<n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream f_wej("przyklad.txt");
    ofstream f_wyj("wynik42.txt");

    vector<string>wyrazy;
    int tab[100];
    for(int i=0; i<100; i++)
    {
        f_wej >> tab[i];
        string wyraz;
        f_wej >> wyraz;
        wyrazy.push_back(wyraz);
    }
    for(int i=0; i<100; i++)
    {
        vector<int>pierwsze;
        if(tab[i] % 2 == 0)
        {
            for(int j=2; j<tab[i]; j++)
                if(Pierwsze(j)) pierwsze.push_back(j);
            
            int najw = 0, najm = 0;
            for(int j=0; j<pierwsze.size(); j++)
            {
                for(int k=0; k<pierwsze.size(); k++)
                {
                    if( pierwsze[j] + pierwsze[k] == tab[i])
                    {
                        if(abs(pierwsze[j] - pierwsze[k]) > abs(najw - najm) || (najw == 0 && najm == 0))
                        {
                            najw = pierwsze[j];
                            najm = pierwsze[k];
                        }
                    }

                }
            }
            f_wyj << tab[i] << ' ' << najm << ' ' <<najw <<endl;
        }
    }
    
    for(int i=0; i<100; i++)
    {
        string ciag, Najciag;
        for(int j=0; j<wyrazy[i].size()-1; j++)
        {
            if(wyrazy[i][j] == wyrazy[i][j+1])
            {
                ciag += wyrazy[i][j];
            }
            else
            {
                ciag += wyrazy[i][j];
                if(ciag.size() > Najciag.size())
                {
                    Najciag = ciag;
                    ciag.clear();
                }
            }
        }
        f_wyj << Najciag.size() << ' ' << Najciag<<endl;
    }

    getchar();
    getchar();
    return 0;
    
}