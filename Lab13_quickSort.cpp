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

int main()
{
    int record1[MAXSIZE];
    memset(record1, 0, MAXSIZE * sizeof(int));
    for (int i = 0; i < MAXSIZE; i++)
    {
        record1[i] = i;
    }
    clock_t srt_time1 = clock();
    quickSort(record1, 0, MAXSIZE - 1, LEFT);
    clock_t end_time1 = clock();
    cout << "Test 1 time used(choose left pivot):" << (double)(end_time1 - srt_time1) / CLOCKS_PER_SEC << 's' << endl;
    clock_t srt_time4 = clock();
    quickSort(record1, 0, MAXSIZE - 1, RANDOM);
    clock_t end_time4 = clock();
    cout << "Test 1 time used(choose random pivot):" << (double)(end_time4 - srt_time4) / CLOCKS_PER_SEC << 's' << endl;

    int record2[MAXSIZE];
    memset(record2, 0, MAXSIZE * sizeof(int));
    for (int i = 0; i < MAXSIZE; i++)
    {
        record2[i] = MAXSIZE - 1 - i;
    }
    clock_t srt_time2 = clock();
    quickSort(record2, 0, MAXSIZE - 1, LEFT);
    clock_t end_time2 = clock();
    cout << "Test 2 time used(choose left pivot):" << (double)(end_time2 - srt_time2) / CLOCKS_PER_SEC << 's' << endl;
    clock_t srt_time5 = clock();
    quickSort(record2, 0, MAXSIZE - 1, RANDOM);
    clock_t end_time5 = clock();
    cout << "Test 2 time used(choose random pivot):" << (double)(end_time5 - srt_time5) / CLOCKS_PER_SEC << 's' << endl;

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
    clock_t srt_time6 = clock();
    quickSort(record3, 0, MAXSIZE - 1, RANDOM);
    clock_t end_time6 = clock();
    cout << "Test 3 time used(choose random pivot):" << (double)(end_time6 - srt_time6) / CLOCKS_PER_SEC << 's' << endl;

    system("pause");
}