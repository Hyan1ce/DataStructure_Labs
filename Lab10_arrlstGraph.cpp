#include <iostream>
using namespace std;

struct edgeNode
{
    int info;           //Ȩֵ
    int tailvex;        //��β������
    int headvex;        //��ͷ������
    edgeNode *headlink; //��ͷ��ͬ����һ����
    edgeNode *taillink; //��β��ͬ����һ����

    edgeNode()
    {
        info = -1;
        tailvex = headvex = 0;
        headlink = taillink = NULL;
    }
};

struct headNode
{
    int data;           //������
    edgeNode *firstIn;  //�Ըö�����Ϊ��ͷ�ĵ�һ����
    edgeNode *firstOut; //�Ըö�����Ϊ��β�ĵ�һ����
    headNode()
    {
        data = 0;
        firstIn = firstOut = NULL;
    }
};

int **nbrList_INIT(int nodeNum)
{
    /**********init**********/
    int **nbrlist;
    nbrlist = new int *[nodeNum];
    for (int i = 0; i < nodeNum; i++)
    {
        nbrlist[i] = new int[nodeNum];
    }
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < nodeNum; j++)
            nbrlist[i][j] = 0;
    }

    /**********cin**********/
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < nodeNum; j++)
            cin >> nbrlist[i][j];
    }

    return nbrlist;
}

headNode *list_INIT(int nodenum, int edgenum, headNode *nodelist, edgeNode *edgelist, int **nbrlist)
{
    headNode *rtnlist = new headNode[nodenum];
    /*init data*/
    for (int i = 1; i <= nodenum; i++)
        rtnlist[i].data = i;

    /*init info,headvex,tailvex*/
    int edgevex = 0;
    for (int i = 0; i < nodenum; i++)
    {
        for (int j = 0; j < nodenum; j++)
        {
            if (nbrlist[i][j] == 1)
            {
                edgelist[edgevex].info = 4 * i + j;
                edgelist[edgevex].headvex = j + 1;
                edgelist[edgevex].tailvex = i + 1;
                edgevex++;
            }
        }
    }

    /*init firstout*/
    for (int row = 0; row < nodenum; row++)
    {
        for (int column = 0; column < nodenum; column++)
        {
            if (nbrlist[row][column] == 1)
            {
                for (int i = 0; i < edgenum; i++)
                {
                    if (edgelist[i].info == row * 4 + column)
                    {
                        nodelist[row].firstOut = &edgelist[i];
                        break;
                    }
                }
                break;
            }
        }
    }

    /*init firstin*/
    for (int column = 0; column < nodenum; column++)
    {
        for (int row = 0; row < nodenum; row++)
        {
            if (nbrlist[row][column] == 1)
            {
                for (int i = 0; i < edgenum; i++)
                {
                    if (edgelist[i].info == row * 4 + column)
                    {
                        nodelist[column].firstIn = &edgelist[i];
                        break;
                    }
                }
                break;
            }
        }
    }

    /*init headlink,taillink*/
    for (int vex = 0; vex < nodenum; vex++)
    {
        // headlink
        if (nodelist[vex].firstIn != NULL)
        {
            for (int i = nodelist[vex].firstIn->tailvex - 1; i < nodenum; i++)
            {
                for (int j = i + 1; j < nodenum; j++)
                {
                    if (nbrlist[j][vex] == 1 && nbrlist[i][vex] == 1)
                    {
                        int start = 0, end = 0;
                        for (int p = 0; p < edgenum; p++)
                        {
                            if (edgelist[p].info == i * 4 + vex)
                            {
                                start = p;
                                break;
                            }
                        }
                        for (int p = 0; p < edgenum; p++)
                        {
                            if (edgelist[p].info == j * 4 + vex)
                            {
                                end = p;
                                edgelist[start].headlink = &edgelist[end];
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        // taillink
        if (nodelist[vex].firstOut != NULL)
        {
            for (int i = nodelist[vex].firstOut->headvex - 1; i < nodenum; i++)
            {
                for (int j = i + 1; j < nodenum; j++)
                {
                    if (nbrlist[vex][j] == 1 && nbrlist[vex][i] == 1)
                    {
                        int start = 0, end = 0;
                        for (int p = 0; p < edgenum; p++)
                        {
                            if (edgelist[p].info == vex * 4 + i)
                            {
                                start = p;
                                break;
                            }
                        }
                        for (int p = 0; p < edgenum; p++)
                        {
                            if (edgelist[p].info == vex * 4 + j)
                            {
                                end = p;
                                break;
                            }
                        }
                        edgelist[start].taillink = &edgelist[end];
                        break;
                    }
                }
            }
        }
    }

    return rtnlist;
}

void show(int nodenum, headNode *nodelist)
{
    for (int i = 0; i < nodenum; i++)
    {
        cout << "\nthe " << i + 1 << " node's relative message:" << endl;
        edgeNode *temp = nodelist[i].firstOut;
        while (temp != NULL)
        {
            cout << temp << '\t'
                 << temp->tailvex << '\t'
                 << temp->headvex << '\t'
                 << temp->taillink << '\t'
                 << temp->headlink << ';';
            temp = temp->taillink;
        }
    }
}

int main()
{
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;
    int **nbrlist = nbrList_INIT(nodeNum);

    headNode *nodelist = new headNode[nodeNum];
    edgeNode *edgelist = new edgeNode[edgeNum];

    list_INIT(nodeNum, edgeNum, nodelist, edgelist, nbrlist);

    show(nodeNum, nodelist);

    delete[] nodelist;
    delete[] edgelist;
    system("pause");
}