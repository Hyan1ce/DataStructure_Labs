#include <iostream>
using namespace std;
template <class T>
class ArrayQueue
{
private:
    int maxSize; //最大长度
    int front;   //队头
    int rear;    //队尾
    T *q;        //存放队列元素
public:
    ArrayQueue()
    {
        maxSize = 0;
        front = 0;
        rear = 0;
        length = 0;
    }
    ArrayQueue(int size)
    { //队列长度初始化
        maxSize = size;
        front = rear = 0;
        length = 0;
        q = new T[size];
    }
    ~ArrayQueue()
    {
        delete[] q;
    }

    bool enQueue(const T elem)
    { //入队
        if (((rear + 1) % maxSize) == front)
        {
            cout << "Queue is full!!!" << endl;
            return false;
        }
        q[rear] = elem;
        rear = (rear + 1) % maxSize;
        return true;
    }
    bool deQueue(T &elem)
    {
        if (front == rear)
        {
            cout << "Queue is empty!" << endl;
            return false;
        }
        elem = q[front];
        front = (front + 1) % maxSize;
        return true;
    }
    T maxElem(T *, int size); //求size长度的数组中最大元素
    void Run(int numWin);     //运行
};

template <class T>
T ArrayQueue<T>::maxElem(T *arr, int size)
{ //求size长度的数组中最大元素
    T maxnum = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= maxnum)
        {
            maxnum = arr[i];
        }
        else
        {
            continue;
        }
    }
    return maxnum;
}

template <class T>
void ArrayQueue<T>::Run(int numWin)
{
    cout << "input the items of the queue:" << endl;
    int c;
    char d;
    while (cin >> c)
    {
        enQueue(c);
        d = getchar();
        if (d == '\n')
            break;
    }
    for (int i = 0; i < maxSize - numWin; i++)
    {
        int runNum = maxElem(&q[i], numWin);
        int deNum = 0;
        deQueue(deNum);
        cout << runNum << " ";
    }
}

int main()
{
    cout << "input the n and k:" << endl;
    int n, k;
    cin >> n >> k;
    ArrayQueue<int> windows(n + 1);
    windows.Run(k);
    system("pause");
}