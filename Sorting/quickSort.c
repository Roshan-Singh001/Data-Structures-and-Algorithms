#include <stdio.h>
#include <stdlib.h>
void show(int a[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int j = high;
    for (int i = high; i > low; i--)
    {
        if (a[i] >= pivot)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j--;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick_sort(int a[], int low, int high)
{
    show(a,5);
    if (low < high)
    {
        int partitionIndex = partition(a, low, high);
        quick_sort(a, low, partitionIndex - 1);
        quick_sort(a, partitionIndex + 1, high);
    }
}

int main()
{
    int size;
    printf("Size of the Array: ");
    scanf("%d", &size);
    int *a = (int*) malloc(size * sizeof(int));
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    show(a, size);
    quick_sort(a, 0, size - 1);
    printf("\n");
    show(a, size);
    free(a);
    return 0;
}