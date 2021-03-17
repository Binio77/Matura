#include<iostream>
#include<fstream>
#include<climits>
#include<vector>
#include<algorithm>
#include <set>

using namespace std;

int main()
{
    ifstream f_wej("dane4.txt");
    ofstream f_wyj("zadanie4,3.txt");
    int tab[1000];
    vector<int> luki;

    for(int i=0; i<1000; i++)
        f_wej >> tab[i];

    for(int i=0; i<999; i++)
    {
        int roznica = abs(tab[i] - tab[i+1]);
        luki.push_back(roznica);
    }
    vector<int> elementy;
    for(int i=0; i<luki.size(); i++)
    {
        elementy.push_back(count(luki.begin(), luki.end(), luki[i]));
    }
    int maks = *max_element(elementy.begin(), elementy.end());
    f_wyj << maks << endl;
    set<int> powtorki;
    for(int i=0; i<luki.size(); i++)
    {
        if(elementy[i] == maks)
            powtorki.insert(luki[i]);
    }
    for( auto i = powtorki.begin(); i != powtorki.end(); ++i)
        f_wyj << * i << ' ';

    

    getchar();
    getchar();
    return 0;
}