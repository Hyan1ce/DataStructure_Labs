#include <iostream>
using namespace std;
template <class T>
class ArrayList
{
private:
    T *alist;      //存储实例
    int maxLength; //最大长度
    int curLen;    //当前长度
public:
    ArrayList()
    {
        maxLength = 0;
        curLen = 0;
    }
    ArrayList(const int maxlength)
    {
        this->maxLength = maxlength;
        alist = new T[maxlength];
        curLen = 0;
        for (int i = 0; i < maxlength; i++)
        {
            this->alist[i] = 0;
        }
    }
    ~ArrayList() {}
    void show();
    bool setValue(const int index, const T value);
    ArrayList operator+(ArrayList arrlist);
};

template <class T>
bool ArrayList<T>::setValue(const int index, const T value)
{
    if (index > this->maxLength || index < 0)
    {
        return false;
    }
    else
    {
        this->alist[index] = value;
        this->curLen++;
        return true;
    }
}

template <class T>
void ArrayList<T>::show()
{
    for (int position = this->maxLength - 1; position >= 0; position--)
    {
        if (this->alist[position] != 0)
        {
            cout << this->alist[position] << " " << position << " ";
        }
        else
        {
            continue;
        }
    }
}

template <class T>
ArrayList<T> ArrayList<T>::operator+(ArrayList arrlist)
{
    for (int index = 0; index < this->maxLength; index++)
    {
        this->alist[index] += arrlist.alist[index];
    }
    return *this;
}

int main()
{
    /*--------------1--------------*/
    cout << "input the first polynomial:" << endl;
    //输入多项式信息
    int num1, index1 = 0;
    int num1List[50] = {0}; //存储输入1的数组，初始化为0
    //输入多项式信息
    while (cin >> num1)
    {
        num1List[index1] = num1;
        index1++;
        char ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }
    /*--------------2--------------*/
    cout << "input the second polynomial:" << endl;
    int num2List[50] = {0}; //存储输入2的数组,初始化为0
    int num2, index2 = 0;
    //输入多项式信息
    while (cin >> num2)
    {
        num2List[index2] = num2;
        index2++;
        char ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }
    int maxPower = num1List[1] >= num2List[1] ? num1List[1] : num2List[1];
    ArrayList<int> arrlist1(maxPower + 1), arrlist2(maxPower + 1); //初始化两个对象
    for (int i = 0; i < index1; i = i + 2)
    {
        arrlist1.setValue(num1List[i + 1], num1List[i]);
    }
    for (int i = 0; i < index2; i = i + 2)
    {
        arrlist2.setValue(num2List[i + 1], num2List[i]);
    }
    ArrayList<int> arrlist = arrlist1 + arrlist2;
    arrlist.show();
    system("pause");
}