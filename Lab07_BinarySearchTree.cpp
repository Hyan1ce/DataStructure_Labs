#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 200

template <class T>
class BiTNode
{
private:
    T elem;
    BiTNode *lchild, *rchild;

public:
    BiTNode()
    {
        elem = 0;
        lchild = rchild = NULL;
    }
    BiTNode(T element)
    {
        elem = element;
        lchild = rchild = NULL;
    }
    ~BiTNode() {}

    void SearchTree_init();                                //初始化二叉搜索树
    void SearchTree_insert(BiTNode *root, BiTNode *child); //插入结点
    void TraverseBiTree(BiTNode *t);                       //先序遍历二叉树
    void visit();                                          //访问元素
    void runTree();                                        //按要求设计的运行函数
};

template <class T>
void BiTNode<T>::SearchTree_init()
{
    BiTNode rootNode;
    cout << "Input:" << endl;
    cin >> rootNode.elem;

    int num;
    int nodeIndex = 0;
    BiTNode *node = new BiTNode[MAX_QUEUE_SIZE];
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        node[i].elem = 0;
    }

    char c = ' ';
    while (c != '\n')
    {
        cin >> num;
        c = getchar();
        node[nodeIndex].elem = num;
        SearchTree_insert(&rootNode, &node[nodeIndex]);
        nodeIndex++;
    }
    TraverseBiTree(&rootNode);
}

template <class T>
void BiTNode<T>::SearchTree_insert(BiTNode *root, BiTNode *child)
{
    while (root != NULL)
    {
        if (child->elem < root->elem)
        {
            if (root->lchild == NULL)
            {
                root->lchild = child;
                break;
            }
            else
                root = root->lchild;
        }
        else if (child->elem > root->elem)
        {
            if (root->rchild == NULL)
            {
                root->rchild = child;
                break;
            }
            else
                root = root->rchild;
        }
        else
            return;
    }
}

template <class T>
void BiTNode<T>::TraverseBiTree(BiTNode *t)
{
    if (t == NULL)
        return;
    t->visit();
    TraverseBiTree(t->lchild);
    TraverseBiTree(t->rchild);
}

template <class T>
void BiTNode<T>::visit()
{
    cout << this->elem << ' ';
}

template <class T>
void BiTNode<T>::runTree()
{
    this->SearchTree_init(); //初始化
}

int main()
{
    BiTNode<int> Tree;
    Tree.runTree();
    system("pause");
}