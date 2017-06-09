#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int size_a(int * data);
static void printa(int * data, int size);
void swap(int * a, int * b);
int part(int* data, int size, int low, int high);
void _quick_sort(int* data, int size, int low, int high);
static void quick_sort(int* data);

int main (void)
{
    int data[] = {1, 5, 9, 10, 3, 4, 1, 6};

    quick_sort(data);
    
    printa(data, size_a(data));

    return 0;
}

static int size_a(int * data)
{
    return sizeof(data)/sizeof(data[0]);
}

static void printa(int * data, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", data[i]);
    }
}

static void quick_sort(int* data)
{
    int size = size_a(data);
    _quick_sort(data, size, 0, size - 1);
}

void _quick_sort(int* data, int size, int low, int high)
{
    if (low < high)
    {
        int pi;
        
        printa(data, size);

        pi = part(data, size, low, high);
        printf("Si: %d - %d - %d\n", pi, low, pi - 1);
        printf("Si: %d - %d - %d\n", pi, pi + 1, high);

        printa(data, size);
        sleep(1);
        
        _quick_sort(data, size, low, pi - 1);
        _quick_sort(data, size, pi + 1, high);
    }
}

int part(int* data, int size, int low, int high)
{
    int i = low;
    int j = low - 1;
    
    int pivot = data[high];

    for (; i < high; i++)
    {
        printf("\nCompare: %d, %d\n", data[i], data[high]);
        if (data[i] <= pivot)
        {
            j += 1;

            if (data[i] < pivot)
            {
                swap(&data[i], &data[j]);
            }

        }
    }


    swap(&data[j + 1], &data[high]);
    return j + 1;
}

void swap(int* a, int* b)
{
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;
}
