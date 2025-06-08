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

void merge(int a[], int mid, int low, int high){
    int *b = (int*) malloc((high+1) * sizeof(int));
    int i = low, k = low, j = mid+1;
    while (i <= mid && j <= high)
    {
        if(a[i] < a[j]){
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        } 
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
    free(b);
}

void merge_sort(int a[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,mid,low,high);
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
    merge_sort(a,0,size-1);
    printf("\n");
    show(a,size);
    free(a);
    return 0;
}