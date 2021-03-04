#include <iostream>
#include <fstream>
using namespace std;

char codificare(char c)
{
    if (isalpha(c))
    {
        c = toupper(c);
        if ((int)c <= (int)'L')
            c = (char)((int)c + (int)'O' - (int)'A');
        else
            c = (char)((int)c - ((int)'M' - (int)'A'));
    }
    return c;
}

void afisareOrdine(char alfabet[26], int litere[26])
{
    cout << endl;
    cout << endl;
    for (int i = 0; i < 26; i++)
        cout << litere[i] << ' ';

    cout << endl;
    for (int i = 0; i < 26; i++)
        cout << alfabet[i] << ' ';
}

char ch;
int litere[26];
int nrChar;
float procente[26];
float distributieNormala[26] = { 8.12 , 1.49 , 2.71 , 4.32 , 12.02 , 2.30 , 2.03 , 5.92 , 7.31 , 0.10 , 0.69 , 3.98 , 2.61 , 6.95 , 7.68 , 1.82 , 0.11 , 6.02 , 6.28 , 9.10 , 2.88 , 1.11 , 2.09 , 0.17 , 2.11 , 0.07};
                                 //a    b      c        d       e      f       g    h       i       j      k    l       m      n      o     p       q       r     s     t       u       v     w     x       y       z
int main()
{

    ifstream inFile;
    inFile.open("D:\\Scoala\\IC\\roman.txt");
    ofstream outFile;
    outFile.open("D:\\Scoala\\IC\\codificat.txt");
    while (inFile >> ch) 
    {
        if (isalpha(ch))
        {
            cout << codificare(ch);
            litere[(int)((int)codificare(ch) - (int)'A')]++;
            outFile << codificare(ch);
        }
    }

    char alfabet[26], litera;
    for (int i = 0; i < 26; i++)
    {
        alfabet[i] = (char)((int)'A' + i);
    }

    afisareOrdine(alfabet, litere);
    
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
        {
            if (litere[j] < litere[j + 1])
            {
                swap(litere[j], litere[j + 1]);
                swap(alfabet[j], alfabet[j + 1]);
            }
        }

    afisareOrdine(alfabet, litere);

    for (int i = 0; i < 26; i++)
    {
        nrChar = nrChar + litere[i];
    }

    cout << endl << nrChar;
   
    for (int i = 0; i < 26; i++)
    {
        procente[i] = ((float)litere[i] / (float)nrChar) * 100;
    }

    cout << endl;
    for (int i = 0; i < 26; i++)
    {
        printf("%.2f", procente[i]);
        cout << ' ';
    }

    return 0;
}
