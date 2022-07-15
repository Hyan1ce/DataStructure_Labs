#include <iostream>
using namespace std;

class Node
{
public:
    int father;
    int root;
    Node()
    {
        father = 0;
        root = 0;
    }
    Node(int elememt, int fa, int ro)
    {
        father = fa;
        root = ro;
    }
};

int findRoot(int n, Node *set)
{
    int root = n;
    while (n != set[n].father)
    {
        root = set[n].father;
    }
    return root;
}

bool unionSet(int father, int child, Node *set)
{
    if (set[father].root != set[child].root)
    {
        set[child].father = father;
        set[child].root = set[father].root;
    }
    return true;
}

int main()
{
    Node *set;

    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    /*******init set*******/
    set = new Node[nodeNum + 1];
    for (int i = 0; i <= nodeNum; i++)
    {
        set[i].father = i;
        set[i].root = findRoot(i, set);
    }

    /*******union set*******/
    for (int i = 1; i <= edgeNum; i++)
    {
        int fa, child;
        cin >> fa >> child;
        unionSet(fa, child, set);
    }

    /*******print result*******/
    int root = 0;
    for (int i = 1; i <= nodeNum; i++)
    {
        if (set[i].root != root)
            cout << '\n';
        cout << i << ' ';
        root = set[i].root;
    }
    system("pause");
}