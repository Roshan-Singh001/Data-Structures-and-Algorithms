#include <stdio.h>
#include <stdlib.h>

void show(int a[], int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
}
void insertion_sort(int *a, int size){
    for (int i = 1; i < size; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j]) a[j+1] = a[j--];
        a[j+1] = key;
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
        printf("Enter Element %d: ",i+1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    show(a,size);
    insertion_sort(a,size);
    printf("\n");
    show(a,size);
    free(a);
    return 0;
}