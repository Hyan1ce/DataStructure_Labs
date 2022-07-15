#include <iostream>
using namespace std;
#define MAX_ARRAY_LENGTH 30

int findMin(int *temp, int *state, int length)
{ // find the index of the minimum in array
    int index = -1, min = 100000;
    for (int i = 0; i < length; i++)
    {
        if (min >= temp[i] && state[i] == 0)
        {
            min = temp[i];
            index = i;
        }
    }
    return index;
}

void exchange_choose_sort(int *buffer, int heap)
{
    int *state = new int[heap]; // record the state of each elem in buffer
    for (int i = 0; i < heap; i++)
    { // init state
        state[i] = 0;
    }

    int *temp = new int[heap];
    for (int i = 0; i < heap; i++)
    {
        temp[i] = buffer[i];
    }
    int endMin = 0;

    for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
    {
        int index = findMin(temp, state, heap);
        if (index == -1)
        {
            cout << '\n';
            for (int i = 0; i < heap; i++)
            { // init state
                state[i] = 0;
            }
            index = findMin(temp, state, heap);
            endMin = 0;
        }
        if (temp[index] < endMin)
        {
            i--;
            state[index] = 1;
            continue;
        }
        endMin = temp[index];
        cout << temp[index] << ' ';
        temp[index] = buffer[i + heap];
        if (buffer[i + 1] == -1)
            break;
    }
    delete[] state;
    delete[] temp;
    return;
}

int main()
{
    int *buffer = new int[MAX_ARRAY_LENGTH];
    for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
    {
        buffer[i] = -1;
    }

    int index = 0;
    char c = '\0';
    while (cin >> buffer[index])
    {
        char c = getchar();
        index++;
        if (c == '\n')
            break;
    }

    int heap = 0;
    cin >> heap;

    exchange_choose_sort(buffer, heap);
    system("pause");
}