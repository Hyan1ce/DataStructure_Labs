#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
#define MAXSIZE 100000
#pragma comment(linker, "/STACK:102400000,102400000")

void shellSort(int arr[], int num)
{
    int d, i, j;
    for (d = num / 2; d >= 1; d = d / 2)
    {
        for (i = d + 1; i <= num; ++i)
            if (arr[i] < arr[i - d])
            {
                int temp = arr[i];
                for (j = i - d; j > 0 && temp < arr[j]; j -= d)
                    arr[j + d] = temp;
                arr[j + d] = temp;
            }
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
    shellSort(record1, MAXSIZE);
    clock_t end_time1 = clock();
    cout << "Test 1 time used:" << (double)(end_time1 - srt_time1) / CLOCKS_PER_SEC << 's' << endl;

    int record2[MAXSIZE];
    memset(record2, 0, MAXSIZE * sizeof(int));
    for (int i = 0; i < MAXSIZE; i++)
    {
        record2[i] = MAXSIZE - 1 - i;
    }
    clock_t srt_time2 = clock();
    shellSort(record2, MAXSIZE);
    clock_t end_time2 = clock();
    cout << "Test 2 time used:" << (double)(end_time2 - srt_time2) / CLOCKS_PER_SEC << 's' << endl;

    int record3[MAXSIZE];
    memset(record3, 0, MAXSIZE * sizeof(int));
    srand((unsigned)time(NULL));
    for (int i = 0; i < MAXSIZE; i++)
    {
        record3[i] = rand() % MAXSIZE;
    }
    clock_t srt_time3 = clock();
    shellSort(record3, MAXSIZE);
    clock_t end_time3 = clock();
    cout << "Test 3 time used:" << (double)(end_time3 - srt_time3) / CLOCKS_PER_SEC << 's' << endl;

    system("pause");
}