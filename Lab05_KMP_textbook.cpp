#include <iostream>
#include <string.h>
using namespace std;

int *findnext(char *P, int length)
{
    int i = 0;
    int k = -1;
    int m = length;
    int *next = new int[m];
    next[0] = -1;
    while (i < m)
    {
        while (k >= 0 && P[i] != P[k])
            k = next[k];
        i++;
        k++;
        if (i == m)
            break;
        if (P[i] == P[k])
            next[i] = next[k];
        else
            next[i] = k;
    }
    return next;
}

int kmp(char *T, char *P, int *N, int tlen, int plen)
{
    int i = 0;
    int j = 0;
    if (tlen < plen)
        return -1;
    while (i < plen && j < tlen)
    {
        if (i == -1 || T[j] == P[i])
            i++, j++;
        else
            i = N[i];
    }
    if (i >= plen)
        return (plen);
    else
        return -1;
}

int main()
{
    /*----------target string----------*/
    cout << "input the target string:" << endl;
    char c;                 //存储输入字符
    int Clength = 0;        //输入长度
    char charArr[40] = {0}; //存储输入字符串
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        else
        {
            charArr[Clength] = c;
            Clength++;
        }
    }
    charArr[Clength] = '\0'; //中止字符串标志
    /*----------module string----------*/
    cout << "input the module string:" << endl;
    int Olength = 0;
    char moduleArr[20] = {0};
    while (true)
    {
        c = getchar();
        if (c == '\n')
            break;
        else
        {
            moduleArr[Olength] = c;
            Olength++;
        }
    }
    charArr[Olength] = '\0';
    int *next = findnext(moduleArr, Olength);
    for (int i = 0; i < Olength; i++)
        cout << next[i] << " ";
    int kmpResult = kmp(charArr, moduleArr, next, Clength, Olength);
    cout << '\n'
         << kmpResult << endl;
    system("pause");
}