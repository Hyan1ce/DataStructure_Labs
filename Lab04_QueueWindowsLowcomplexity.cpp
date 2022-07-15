#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int q[20], a[20];
int n, k;

void getmax()
{ // 和上面同理
    int head = 0, tail = 0;
    for (int i = 1; i < k; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++)
    {
        while (head <= tail && a[q[tail]] <= a[i])
            tail--;
        q[++tail] = i;
        while (q[head] <= i - k)
            head++;
        printf("%d ", a[q[head]]);
    }
}

int main()
{
    cout << "input the n and k:" << endl;
    scanf("%d%d", &n, &k);
    cout << "input the items of the queue:" << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    getmax();
    system("pause");
    return 0;
}