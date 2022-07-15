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
    bool isEmpty(); //判断是否为空
};

template <class T>
bool arrStack<T>::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

class Calculator
{
private:
    arrStack<int> s;
    bool GetTwoOperands(int &opd1, int &opd2);
    void Compute(char op);

public:
    Calculator(void){};
    void Run(void);
};

bool Calculator::GetTwoOperands(int &opd1, int &opd2)
{
    if (s.isEmpty())
    {
        return false;
    }
    s.pop(opd1);
    if (s.isEmpty())
    {
        return false;
    }
    s.pop(opd2);
    return true;
}

void Calculator::Compute(char op)
{
    bool result;
    int operand1, operand2;
    result = GetTwoOperands(operand1, operand2);
    if (result == true)
    {
        switch (op)
        {
        case '+':
            s.push(operand1 + operand2);
            break;
        case '-':
            s.push(operand1 - operand2);
            break;
        case '*':
            s.push(operand1 * operand2);
            break;
        case '/':
            s.push(operand1 / operand2);
            break;
        }
    }
    else
    {
        s.clear();
    }
}

void Calculator::Run(void)
{
    char c;
    int newOperand, res;
    while (cin >> c, c != '#')
    {
        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
            Compute(c);
            break;
        default:
            cin.putback(c);
            cin >> newOperand;
            s.push(newOperand);
            break;
        }
    }
    if (s.pop(res))
        cout << res << endl;
}

template <class T>
void arrStack<T>::show()
{
    if (this->isEmpty())
        cout << "Empty stack!" << endl;
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
    }
}

int main()
{
    cout << "input the postfix expression:" << endl;
    Calculator clu;
    clu.Run();
    system("pause");
}