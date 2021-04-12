#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream wej("galerie_przyklad.txt");
    map<string, int> kraje;
    string kod, miasto;
    int x[70], y[70];
    int najw = INT_MIN, najm = INT_MAX;
    string najw_miasto, najm_miasto;
    for(int i = 0; i < 10; i++)
    {
        set<int> P;
        wej >> kod >> miasto;
        int liczba_lokali = 0, powierzchnia = 0;
        for(int j = 0; j < 70; j++)
            wej >> x[j] >> y[j];

        kraje[kod]++; 
        int suma = 0;
        for(int j = 0; j < 70; j++)
        {
            suma += x[j] * y[j];
            P.insert(x[j] * y[j]);
            if(x[j] != 0)
                liczba_lokali++;
        }
        powierzchnia = suma;
        cout << miasto << ' ' << powierzchnia << ' ' << liczba_lokali << endl;
        
        int rozne_lokale = P.size()-1;

        if(rozne_lokale > najw)
        {
            najw = rozne_lokale;
            najw_miasto = miasto;
        }

        if(rozne_lokale < najm)
        {
            najm = rozne_lokale;
            najm_miasto = miasto;
        }
        
    }
    for(auto e: kraje)
    {
        cout << e.first << ' ' <<  e.second<<endl;
    }
    cout << najm_miasto << ' ' << najm <<endl;
    
    cout << najw_miasto << ' ' << najw <<endl;
    getchar();
    getchar();
    return 0;
}