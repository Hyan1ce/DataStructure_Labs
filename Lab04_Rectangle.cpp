#include <iostream>
using namespace std;
template <class T>
class arrStack
{
private:
    int mSize;
    int top;
    T *st;

public:
    arrStack(int size)
    {
        mSize = size;
        top = -1;
        st = new T[mSize];
    }
    arrStack()
    {
        mSize = 20;
        top = -1;
        st = new T[mSize];
    }
    ~arrStack()
    {
        delete[] st;
    }
    void clear()
    {
        top = -1;
    }
    void show();
    bool push(const T item)
    {
        if (top == mSize - 1)
        {
            return false;
        }
        else
        {
            st[++top] = item;
            return true;
        }
    }
    bool pop(T &item)
    {
        if (top == -1)
        {
            return false;
        }
        else
        {
            item = st[top--];
            return true;
        }
    }
    bool isEmpty();                      //判断是否为空
    int maxSpace(int index, int sumnum); //矩形面积最大值
    int findindex(int elem);             //元素在栈中第一次出现的位置
    void Run();                          //运行
};

template <class T>
bool arrStack<T>::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

template <class T>
int arrStack<T>::maxSpace(int index, int sumnum)
{ //完全占据第i个柱子的长方形面积
    int leftindex, rightindex;
    arrStack tempstack(20);
    for (int i = 0; i <= index; i++)
    {
        if (tempstack.isEmpty() || tempstack.st[tempstack.top] >= st[index])
        {
            tempstack.push(st[i]);
        }
        else
        {
            tempstack.top = -1;
            continue;
        }
    }
    for (int i = index + 1; i <= sumnum; i++)
    {
        if (tempstack.st[tempstack.top] >= st[index])
        {
            tempstack.push(st[i]);
        }
        else
        {
            break;
        }
    }
    leftindex = this->findindex(tempstack.st[0]);
    rightindex = this->findindex(tempstack.st[tempstack.top]) + 1;
    int space = tempstack.top * st[index];
    return space;
}

template <class T>
int arrStack<T>::findindex(int elem)
{
    for (int i = 0; i < top; i++)
    {
        if (st[i] == elem)
        {
            return i;
        }
    }
    return 0;
}

template <class T>
void arrStack<T>::Run()
{
    cout << "input the items of the Stack:" << endl;
    int c, num = 0;
    char d;
    while (cin >> c)
    {
        num++;
        push(c);
        d = getchar();
        if (d == '\n')
            break;
    }
    //调用函数求六个柱子的面积
    int space[20] = {0};
    for (int i = 0; i < num; i++)
    {
        space[i] = maxSpace(i, num);
    }
    int max = space[0];
    //求六个柱子面积的最大值
    for (int i = 0; i < num / 2; i++)
    {
        max = space[i] >= max ? space[i] : max;
    }
    cout << max << endl;
}

int main()
{
    arrStack<int> arsck(20);
    arsck.Run();
    system("pause");
}