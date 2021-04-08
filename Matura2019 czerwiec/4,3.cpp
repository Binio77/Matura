#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    ifstream wej("pierwsze.txt");
    ofstream wyj("4,3.txt");
    int licznik = 0;
    for(int i = 0; i < 200; i++)
    {
        string liczba, stara;
        wej >> liczba;
        stara = liczba;
        while(stoi(liczba) > 9)
        {
            int suma = 0;
            for(int j = 0; j < liczba.size(); j++)
            {
                suma += static_cast<int>(liczba[j])-48;
            }
            liczba = to_string(suma);
            
        }
        if(stoi(liczba) == 1)
        {
            licznik++;
        }
    }
    wyj << licznik <<endl;
    getchar();
    getchar();
    return 0;
}