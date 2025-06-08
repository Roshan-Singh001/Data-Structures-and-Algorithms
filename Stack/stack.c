#include <stdio.h>

int top = -1;

void peek(int *a,int index){
    printf("\n%d",a[index]);
}
void show_top(int *a){
    printf("\n%d",a[top]);
}
void show_bottom(int *a){
    printf("\n%d",a[0]);
}

void show(int *a){
    printf("\n");
    printf("\n--->%d",a[top]);
    for (int i = top-1; i >=0; i--) printf("\n    %d",a[i]);
}

void push(int *a, int size){
    if (top == size - 1)
    {
        printf("\n--------Overflow\n");
    }
    else
    {
        int element;
        printf("\nEnter element: ");
        scanf("%d",&element);
        top++;
        a[top] = element;
        show(a);
    }
}

void pop(int *a){
    if (top == -1)
    {
        printf("\n--------Underflow\n");
    }
    else
    {
        top--;
        show(a);
    }
}

int main()
{
    int a[11], option, totalSize = 10;
    while (1)
    {
        printf("\nEnter,\n1.PUSH\n2.POP\n3.PEEK\n4.Show Top\n5.Show Bottom\n6.Show\n7.Exit: ");
        scanf("%d", &option);
        if (option == 1) push(a,totalSize);
        else if (option == 2) pop(a);
        else if (option == 3){
            int index;
            printf("\nEnter Index: ");
            scanf("%d",&index);
            peek(a,index);
        } 
        else if (option == 4) show_top(a);
        else if (option == 5) show_bottom(a);
        else if (option == 6) show(a);
        else break;
    }
    return 0;
}