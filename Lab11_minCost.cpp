/*****未完成*****/
#include <iostream>
#define INFIN 200
using namespace std;

enum state
{
    VISITED = 1,
    UNVISITED = 0
};

struct edgeNode
{
    int length;
    int cost;
    edgeNode()
    {
        length = cost = 0;
    }
};

edgeNode dijkstra(int start, int end, int nodenum, edgeNode **nbrlist)
{
    if (start == 0 && end == 0)
    {
        edgeNode rst;
        return rst;
    }
    int *final = new int[nodenum];
    int *dist = new int[nodenum];
    int *path = new int[nodenum];
    for (int i = 0; i < nodenum; i++)
    { // 3 list init
        final[i] = UNVISITED;
        if (!i)
            dist[i] = 0;
        else
            dist[i] = INFIN;
        path[i] = -1;
    }

    for (int i = 0; i < nodenum; i++)
    {
        double mindist = INFIN;
        int index = 0;
        for (int j = 0; j < nodenum; j++)
        { // find the minimum of dist_array
            if (final[j] == UNVISITED && dist[j] < mindist)
            {
                mindist = dist[j];
                index = j;
            }
        }

        final[index] = VISITED;
        for (int k = 0; k < nodenum; k++)
        {
            if (dist[index] + nbrlist[index][k].length < dist[k] && nbrlist[index][k].length != 0)
            {
                dist[k] = dist[index] + nbrlist[index][k].length;
                path[k] = index;
            }
        }
    }

    edgeNode rst;
    return rst;
}

int main()
{
    int nodeNum, edgeNum;
    cin >> nodeNum >> edgeNum;

    edgeNode **nbrlist;
    nbrlist = new edgeNode *[nodeNum];
    for (int i = 0; i < nodeNum; i++)
    {
        nbrlist[i] = new edgeNode[nodeNum];
    }
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < nodeNum; j++)
        {
            nbrlist[i][j].length = 0;
            nbrlist[i][j].cost = 0;
        }
    }

    for (int j = 0; j < edgeNum; j++)
    {
        int a, b, d, p;
        cin >> a >> b >> d >> p;
        nbrlist[a][b].length = d;
        nbrlist[a][b].cost = p;
    }

    int tmp1, tmp2;
    edgeNode result;
    do
    {
        cin >> tmp1 >> tmp2;
        result.length = dijkstra(tmp1, tmp2, nodeNum, nbrlist).length;
        result.cost = dijkstra(tmp1, tmp2, nodeNum, nbrlist).cost;
    } while (tmp1 != 0 && tmp2 != 0);
    cout << "结果:" << result.length << ' ' << result.cost;
    system("pause");
}