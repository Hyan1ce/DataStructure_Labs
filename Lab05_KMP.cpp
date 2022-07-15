#include <iostream>
#include <string>
using namespace std;

class Sstring
{
public:
    int length; //长度
    char *ch;   //用于存储字符串
    Sstring()
    {
        length = 0;
        ch = NULL;
    }
    ~Sstring()
    {
        delete ch;
    }
};

int *nextVector(char *chararray, int length)
{
    int index = 0;
    int *next = new int[length];
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
            next[0] = -1;
        else if (i == 1)
            next[1] = 0;
        else
        {
            for (int j = 0; j < i - 1; j++)
            {
                if (chararray[j] == chararray[i - j])
                    index++;
                else
                    break;
            }
            next[i] = index;
        }
        index = 0;
    }
    return next;
}

int main()
{
    /*----------target string----------*/
    cout << "输入目标字符串:" << endl;
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
    cout << "out!" << endl;
    charArr[Olength] = '\0';
    int *next = nextVector(moduleArr, Olength);
    for (int i = 0; i < Olength; i++)
        cout << next[i] << " ";
    system("pause");
}