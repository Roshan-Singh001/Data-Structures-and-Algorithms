#include <stdio.h>
#include <stdlib.h>
void show(int a[], int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
}

void selection_sort(int *a, int size){
    for (int i = 0; i < size - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[minindex] > a[j]) minindex = j;        
        }
        int temp = a[minindex];
        a[minindex] = a[i];
        a[i] = temp;
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
    selection_sort(a,size);
    printf("\n");
    show(a,size);
    free(a);
    return 0;
}