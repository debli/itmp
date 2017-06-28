#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printa(int *a, int size)
{
    printf("=====================\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
}

class min_heap
{
    private:
        int *heap_arr;
        int capacity;
        int heap_size;


    public:
        min_heap(int capacity);
        int parent(int index);
        int left_child(int index);
        int right_child(int index);
        ~min_heap();
        bool insert(int k);
};

int min_heap::parent(int index)
{
    return ((index - 1) / 2);
};

int min_heap::left_child(int index)
{
    return ((index * 2) + 1);
};

int min_heap::right_child(int index)
{
    return ((index * 2) + 2);
};

min_heap::min_heap(int cap)
{
    try
    {
        heap_arr = new int[cap];
    }
    catch (std::bad_alloc& e)
    {
        cout << "ERROR: could not alloc memory.\n" << std::endl;
        return;
    }

    capacity = cap;
    heap_size = 0;

};

bool min_heap::insert(int k)
{
    if (heap_arr == NULL)
    {
        return false;
    }

    if (heap_size == capacity)
    {
        cout << "ERROR: Overflow, Could not insert k" << endl;
        return false;
    }

    heap_size++;
    int i = heap_size - 1;
    heap_arr[i] = k;

    int pi = parent(i);

    while (i != 0 && heap_arr[i] < heap_arr[pi])
    {
        swap(&heap_arr[i], &heap_arr[pi]);
        i = pi;
        pi = parent(i);
    }

    printa(heap_arr, heap_size);
};


min_heap::~min_heap()
{
    delete [] heap_arr;
    heap_size = 0;
};

int main()
{
    min_heap heap(10);
    heap.insert(8);
    heap.insert(2);
    heap.insert(1);
    heap.insert(4);
    heap.insert(3);
    return 0;
}
