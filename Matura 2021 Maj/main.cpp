#include <bits/stdc++.h>

using namespace std;

int main()
{
    string wyraz;
    ifstream wej ("przyklad.txt");
    char naj_litera;
    int ilosc_najl = 0;
    map<char, int> litery;

    for(int i = 0; i < 20; i++)
    {
        string instrukcja;
        char litera;
        wej >> instrukcja;
        if(instrukcja == "DOPISZ")
        {
            wej >> litera;
            wyraz += litera;
            litery[litera]++;

        }else if(instrukcja == "ZMIEN")
        {
            wej >> litera;
            wyraz[wyraz.size()-1] = litera;
        }else if(instrukcja == "USUN")
        {
            wej >> litera;
            wyraz.erase(wyraz.size()-1);
        }else if(instrukcja == "PRZESUN")
        {
            wej >> litera;
            for(int i = 0; i < wyraz.size(); i++)
            {
                if(litera == wyraz[i])
                {
                    if(wyraz[i] == 'Z')
                       {
                           wyraz[i] = 'A';
                       }
                    else
                    {
                        wyraz[i] += 1;
                    }
                    break;
                }
            }
        }
    }
    cout << wyraz.size() << endl;

    wej.close();
    wej.open("przyklad.txt");
    int ele = 1, naj_ele = 1;
    string poprzedni, naj;
    char smieci;
    wej >> poprzedni;
    naj = poprzedni;
    wej >> smieci;
    for(int i = 0; i < 19; i++)
    {

        string instrukcja;
        wej >> instrukcja;
        wej >> smieci;
        //cout <<"1. " << ele << ' ' << poprzedni << ' ' << instrukcja << ' ' << naj <<endl;
        if(instrukcja == poprzedni)
        {
            ele++;
            if(ele > naj_ele)
            {
                naj_ele = ele;
                naj = poprzedni;
            }
        }else
        {
            poprzedni = instrukcja;
            ele = 1;
        }

        //cout <<"2. " << ele << ' ' << poprzedni << ' ' << instrukcja << ' ' << naj <<endl;
    }
    cout << naj_ele << ' ' << naj<<endl;
    cout << wyraz << endl << endl;
    for(auto e:litery)
    {
        cout << e.first << ' ' << e.second << endl;
    }
    
    getchar();
    getchar();
    return 0;
}
