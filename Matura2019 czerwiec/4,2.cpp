#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool pierwsze(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ifstream wej("pierwsze.txt");
    ofstream wyj("4,2.txt");
    for(int i = 0; i < 200; i++)
    {
        string liczba, stary;
        wej >> liczba;
        stary = liczba;
        reverse(liczba.begin(), liczba.end());
        int n;
        n = stoi(liczba);
        if(pierwsze(n))
            wyj << stary <<endl;
    }

    getchar();
    getchar();
    return 0;
}