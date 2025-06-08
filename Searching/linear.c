#include <stdio.h>

int main()
{
    int a[] = {1,2,3,4,5};
    int size = 5, val,temp = 1;

    printf("Enter value: ");
    scanf("%d",&val);

    for (int i = 0; i < size; i++)
    {
        if (a[i] == val)
        {
            printf("\n%d is found at index %d",val,i);
            temp = 0;
            break;
        }   
    }
    if (temp)   
    {
        printf("\n%d not found",val);
    }
    
    
    return 0;
}