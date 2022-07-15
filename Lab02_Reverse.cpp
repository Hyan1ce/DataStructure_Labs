#include <iostream>
using namespace std;
template <class T>
class Node
{ //结点类
public:
	T value;
	Node<T> *next; //指向下一个结点的指针
	Node()
	{ //无参数构造函数
		value = 0;
		next = NULL;
	}
	Node(const T value, Node<T> *nextptr)
	{ //值与指针构造函数
		this->value = value;
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
	bool insert(const int index, const T value);					   //插入
	Linklist<T> add(const Linklist<T> list, int length1, int length2); //链表加法
};

template <class T>
void Linklist<T>::show() const
{ //打印输出函数
	Node<T> *p = this->head;
	for (int i = 0; i < 50; i = i + 2)
	{
		if (p->next != NULL && p->value != 0)
		{
			cout << p->value << " ";
		}
		else if (p->next == NULL)
		{
			cout << p->value;
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
bool Linklist<T>::insert(const int index, const T value)
{ //在指定位置插入结点
	Node<T> *p, *q;
	if ((p = this->setPos(index - 1)) == NULL)
	{
		return false;
	}
	q = new Node<T>(value, p->next);
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
	p2 = list.head;
	for (int i = 0; i < length2; i++)
	{ //确定插入位置
		p2 = p2->next;
		p1 = this->head;
		for (int j = 0; j < length1; j++)
		{
			p1 = p1->next;
			if (p2->value < p1->value)
			{
				if (p1->next == NULL || p2->value >= p1->next->value)
				{ //下一个指针是空指针/介于二者之间，插入
					insertIndex = j + 1;
					this->insert(insertIndex, p2->value);
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
	cout << "input the first linklist:" << endl;
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
	cout << "input the second linknlist:" << endl;
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
	//初始化数组，并将输入元素倒序存入:
	int reverseList1[20] = {0};
	int reverseList2[20] = {0};
	for (int i = 0; i < index1; i++)
	{
		reverseList1[index1 - i] = num1List[i];
	}
	for (int i = 0; i < index2; i++)
	{
		reverseList2[index2 - i] = num2List[i];
	}
	//初始化两个链表
	for (int i = 1; i <= index1; i++)
	{ //初始化链表1
		Node<int> linklist;
		linklist.value = reverseList1[i];
		linlist1.insert(i - 1, linklist.value);
	}
	for (int i = 1; i <= index2; i++)
	{ //初始化链表2
		Node<int> linklist;
		linklist.value = reverseList2[i];
		linlist2.insert(i - 1, linklist.value);
	}
	Linklist<int> returnLinklist = linlist2.add(linlist1, index2, index1);
	returnLinklist.show();
	system("pause");
	return 0;
}