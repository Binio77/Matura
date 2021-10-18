#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

string reverse_(string wyraz)
{
    string nazwa;
    for(int i=wyraz.size()-1;i>=0;i--)
    {
        nazwa += wyraz[i]; 
    }
    return nazwa;
}

int main()
{
    ifstream wej("identyfikator_przyklad.txt");
    int najwsuma;
    for(int i = 0; i<20; i++)
    {
        int const letterOffset = 'A' - 10;
        string name, letters, numbers;
        int suma = 0;
        wej >> name;
        for(int j = 3; j < 9; j++)
        {
            numbers += name[j];
            suma += (int) name[j]-48;
        }
        for(int j = 0; j < 3 ; j++)
            letters += name[j];

        if(najwsuma < suma)
            najwsuma = suma;

        //if(reverse_(letters) == letters || reverse_(numbers) == numbers)
            //cout << name << endl;

        int iloczyn = ((int)name[0]- letterOffset) *7 + ((int)name[1]- letterOffset) *3 + ((int)name[2]- letterOffset) *1 + ((int)name[4]-'0')*7 + ((int)name[5]- '0')*3 + ((int)name[6]- '0')*1 + ((int)name[7]- '0')*7 + ((int)name[8]- '0')*3;
        if(iloczyn % 10 != (int)name[3]-'0')
            cout << name << endl;
        //int iloczyn = 0;
        //iloczyn = ((int)name[0])-55 *7;
            
    }
    //cout << najwsuma << endl;
    getchar();
    getchar();
    return 0;
}