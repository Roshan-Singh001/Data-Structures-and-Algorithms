#include <stdio.h>
#include <stdlib.h>
void show(int a[], int size){
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
}

void bubble_sort(int *a, int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
            
        }
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
    bubble_sort(a,size);
    printf("\n");
    show(a,size);
    free(a);
    return 0;
}