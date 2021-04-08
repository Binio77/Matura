#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

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
    ifstream wej("liczby_przyklad.txt");
    ofstream wyj("4,1.txt");
    vector<int> liczby;
    for(int i = 0; i < 50; i++)
    {
        int liczba;
        wej >> liczba;
        if(pierwsze(liczba) && liczba < 5001 && liczba > 99)
            liczby.push_back(liczba);
    }
    sort(liczby.begin(), liczby.end());
    for(int i = 0; i < liczby.size(); i++)
        wyj << liczby[i]<<endl;
    getchar();
    getchar();
    return 0;
}