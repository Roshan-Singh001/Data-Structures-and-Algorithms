#include <stdio.h>

int main()
{
    int a[10] = {0,2,3,4,5};
    int element, size = 5;
    int low = 0, high = size - 1, mid,temp = 1;
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Enter element: ");
    scanf("%d", &element);
    
    while (low <= high)
    {
        mid = (low+high)/2;
        if (a[mid] == element)
        {
            printf("\n%d is found at %d.",element,mid);
            temp = 0;
            break;
        }
        else if (a[mid] > element) high = mid-1;
        else if(a[mid] < element) low = mid+1;
    }
    if(temp)
    {
        printf("\nNot Found");
    } 
    return 0;
}