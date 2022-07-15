#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#define MAXSIZE 10000
#pragma comment(linker, "/STACK:102400000,102400000")

enum state
{ // model of pivot
    LEFT = 1,
    RANDOM = 0
};

int findPivot(int arr[], int low, int high, int model)
{ // choose element as pivot
    int pivot = 0;
    if (model) // left pivot
        pivot = arr[low];
    else // random pivot
        pivot = arr[rand() % MAXSIZE];
    while (low < high)
    {
        while (low < high && arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quickSort(int arr[], int low, int high, int model)
{
    if (low < high)
    {
        int tmPivot = findPivot(arr, low, high, model);
        quickSort(arr, low, tmPivot - 1, model);
        quickSort(arr, tmPivot + 1, high, model);
    }
}

int findElem(int arr[], int power, int len)
{
    int target = arr[len - 1];
    int tmp = 0;
    while (tmp < power)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (target > arr[i])
            {
                tmp++;
                target = arr[i];
            }
        }
    }
    return tmp;
}

int main()
{
    int record3[MAXSIZE];
    memset(record3, 0, MAXSIZE * sizeof(int));
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAXSIZE; i++)
    {
        record3[i] = rand() % MAXSIZE;
    }

    clock_t srt_time3 = clock();
    quickSort(record3, 0, MAXSIZE - 1, LEFT);
    clock_t end_time3 = clock();
    cout << "Test 3 time used(choose left pivot):" << (double)(end_time3 - srt_time3) / CLOCKS_PER_SEC << 's' << endl;
    int rndNum = rand() % MAXSIZE;
    int out = findElem(record3, rndNum, MAXSIZE);
    cout << "The " << rndNum << " biggest num in array is " << out << endl;

    system("pause");
}