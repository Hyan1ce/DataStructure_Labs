#include <iostream>
#include <math.h>
#define INFIN 200
using namespace std;

struct headNode
{
    int x;
    int y;

    headNode()
    {
        x = y = -1;
    }
};

enum state
{
    VISITED = 1,
    UNVISITED = 0
};

double distance(headNode node1, headNode node2)
{
    /*****Distance between two points*****/
    double tmp = sqrt(pow(abs(node2.x - node1.x), 2) + pow(abs(node2.y - node1.y), 2));
    return tmp;
}

double dijkstra(int start, int end, int nodenum, double **nbrlist)
{
    int *final = new int[nodenum];
    double *dist = new double[nodenum];
    int *path = new int[nodenum];
    for (int i = 0; i < nodenum; i++)
    { // 3 list init
        final[i] = UNVISITED;
        if (!i)
            dist[i] = 0.00;
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
            if (dist[index] + nbrlist[index][k] < dist[k] && nbrlist[index][k] != 0)
            {
                dist[k] = dist[index] + nbrlist[index][k];
                path[k] = index;
            }
        }
    }

    return dist[end - 1];
}

int main()
{
    int nodeNum, edgeNum;
    cin >> nodeNum;

    /*****node array init*****/
    headNode *nodelist = new headNode[nodeNum];
    for (int num = 0; num < nodeNum; num++)
    {
        cin >> nodelist[num].x >> nodelist[num].y;
    }

    /*****neighbor array init*****/
    double **nbrlist;
    nbrlist = new double *[nodeNum];
    for (int i = 0; i < nodeNum; i++)
    {
        nbrlist[i] = new double[nodeNum];
    }
    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = 0; j < nodeNum; j++)
            nbrlist[i][j] = 0.00;
    }

    /*****edge array init*****/
    cin >> edgeNum;
    int x = -1, y = -1;
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> x >> y;
        nbrlist[x - 1][y - 1] = distance(nodelist[x - 1], nodelist[y - 1]);
    }

    /*****show result*****/
    cin >> x >> y;
    double minlength = dijkstra(x, y, nodeNum, nbrlist);
    printf("%.2f", minlength);

    delete[] nodelist;
    delete[] nbrlist;
    system("pause");
}