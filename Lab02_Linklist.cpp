#include <iostream>
using namespace std;
template <class T>
class Node
{ //结点类
public:
	T power;	   //幂次
	T coefficient; //系数
	Node<T> *next; //指向下一个结点的指针
	Node()
	{ //无参数构造函数
		power = 0;
		coefficient = 0;
		next = NULL;
	}
	Node(const T power, const T coefficient, Node<T> *nextptr)
	{ //值与指针构造函数
		this->power = power;
		this->coefficient = coefficient;
		this->next = nextptr;
	}
	Node(Node<T> *nextptr)
	{ //指针构造函数
		this->next = nextptr;
	}
};

template <class T>
class Linklist
{
public:
	Node<T> *head, *tail;
	Linklist()
	{ //无参数构造函数
		head = NULL;
		tail = NULL;
	}
	Linklist(const Node<T> *head, const Node<T> *tail)
	{ //头指针、尾指针构造函数
		this->head = head;
		this->tail = tail;
	}
	Linklist(const Node<T> *head)
	{ //单头指针构造函数
		this->head = head;
	}
	Linklist(const int size)
	{ //链表长度初始化
		head = tail = new Node<T>[size];
	}
	void show() const;												   //按格式打印输出
	Node<T> *setPos(const int index);								   //返回指向第index个元素的指针值
	bool insert(const int index, const T value1, const T value2);	   //插入
	Linklist<T> add(const Linklist<T> list, int length1, int length2); //链表加法
};

template <class T>
void Linklist<T>::show() const
{ //打印输出函数
	Node<T> *p = this->head;
	for (int i = 0; i < 50; i = i + 2)
	{
		if (p->next != NULL && p->coefficient != 0 && p->power != 0)
		{
			cout << p->coefficient << " ";
			cout << p->power << " ";
		}
		else if (p->next == NULL)
		{
			cout << p->coefficient << " ";
			cout << p->power << " ";
			break;
		}
		p = p->next;
	}
}

template <class T>
Node<T> *Linklist<T>::setPos(const int index)
{ //返回指向第index个元素的指针值
	int count = 0;
	if (index == -1)
	{ //索引为-1返回头指针
		return head;
	}
	Node<T> *p = new Node<T>(head->next);
	while (p != NULL && count <= index)
	{
		p = p->next;
		count++;
	}
	return p;
}

template <class T>
bool Linklist<T>::insert(const int index, const T power, const T coefficient)
{ //在指定位置插入结点
	Node<T> *p, *q;
	if ((p = this->setPos(index - 1)) == NULL)
	{
		return false;
	}
	q = new Node<T>(power, coefficient, p->next);
	p->next = q;
	if (p == tail)
		tail = q;
	return true;
}

template <class T>
Linklist<T> Linklist<T>::add(const Linklist<T> list, int length1, int length2)
{							  //实现链表相加，按幂次排列
	int insertIndex = 0;	  //初始化插入位置
	Node<T> *p1 = this->head; //第一个链表元素的头指针
	Node<T> *p2 = list.head;  //第二个链表元素的头指针
	for (int i = 0; i < length1; i++)
	{ //判断是否相等
		p1 = p1->next;
		p2 = list.head;
		for (int j = 0; j < length2; j++)
		{
			p2 = p2->next;
			if (p2->power == p1->power)
			{
				p1->coefficient += p2->coefficient;
			}
			else
			{
				continue;
			}
		}
	}
	p2 = list.head;
	for (int i = 0; i < length2; i++)
	{ //确定插入位置
		p2 = p2->next;
		p1 = this->head;
		for (int j = 0; j < length1; j++)
		{
			p1 = p1->next;
			if (p2->power < p1->power)
			{
				if (p1->next == NULL || p2->power > p1->next->power)
				{ //下一个指针是空指针/介于二者之间，插入
					insertIndex = j + 1;
					this->insert(insertIndex, p2->power, p2->coefficient);
					length1 += 1;
					break;
				}
			}
		}
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
	Linklist<int> linlist1(20), linlist2(20); //初始化两个链表，分别分配20个int空间
	//初始化两个链表
	for (int i = 0; i < index1; i = i + 2)
	{ //初始化链表1
		Node<int> linklist;
		linklist.power = num1List[i + 1];
		linklist.coefficient = num1List[i];
		linlist1.insert(i / 2, linklist.power, linklist.coefficient);
	}
	for (int i = 0; i < index2; i = i + 2)
	{ //初始化链表2
		Node<int> linklist;
		linklist.power = num2List[i + 1];
		linklist.coefficient = num2List[i];
		linlist2.insert(i / 2, linklist.power, linklist.coefficient);
	}
	Linklist<int> returnLinklist = linlist1.add(linlist2, index1 / 2, index2 / 2);
	returnLinklist.show();
	system("pause");
	return 0;
}
