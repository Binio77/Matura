#include<iostream>
#include<utility>
#include<fstream>
#include<vector>
#include<climits>
#include<string>
using namespace std;

int main()
{
    ifstream f_wej("pary.txt");
    ofstream f_wyj("wynik43.txt");
    vector<int> liczby(100);
    vector<string> wyrazy(100);
    for(int i=0; i<100; i++)
    {
        f_wej >> liczby[i];
        f_wej >> wyrazy[i];
        cout<<liczby[i] <<' '<<wyrazy[i]<<endl;
    }

    int najmliczba = 0;
    string najmwyraz;


    for(int i=1; i<100; i++)
    {
        if(liczby[i] == wyrazy[i].size())
        {
            if(liczby[i] < najmliczba || najmliczba == 0)
            {   
                najmliczba = liczby[i];
                najmwyraz = wyrazy[i];
            }
            else if (liczby[i] == najmliczba)
                if(wyrazy[i] < najmwyraz)
                {
                    najmliczba = liczby[i];
                    najmwyraz = wyrazy[i];
                }
                    
        }
    }
    f_wyj << najmliczba << ' ' << najmwyraz<<endl;

    getchar();
    getchar();
    return 0; 
}
