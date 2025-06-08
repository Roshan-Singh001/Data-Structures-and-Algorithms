#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int capacity;
    int top;
    int *a;
};

int isFull(struct Stack *s){
    return s->top == s->capacity-1;
}

int isEmpty(struct Stack *s){
    return s->top == -1;
}

void show_top(struct Stack *s){
    if (isEmpty(s)) printf("\nStack is Empty");
    else printf("\nTop is: %d",s->a[s->top]);
}

void show_bottom(struct Stack *s){
    if (isEmpty(s)) printf("\nStack is Empty");
    else printf("\nBottom is: %d",s->a[0]);
}

void show(struct Stack *s){
    printf("\n");
    printf("\n--> %d",s->a[s->top]);
    for (int i = s->top-1; i >= 0; i--)
    {
        printf("\n    %d",s->a[i]);
    }
    
}

void peek(struct Stack *s){
    if (isEmpty(s)) printf("\nStack Is Empty.");
    else
    {
        int index;
        printf("\nEnter Index: ");
        scanf("%d",&index);
        printf("\n%d",s->a[index]);
    }
}

void push(struct Stack *s){
    if (isFull(s)) printf("\n----Overflow !!!");
    else
    {
        int val;
        printf("\nEnter Element: ");
        scanf("%d", &val);
        s->top++;
        s->a[s->top] = val;
        printf("\n***Pushed Successfully");
    }
}

void pop(struct Stack *s){
    if (isEmpty(s)) printf("\n----Underflow !!!");
    else
    {
        s->top--;
        printf("\n***Poped Successfully");
    }
}


int main()
{
    struct Stack* s;
    int option;
    s->capacity = 10;
    s->a = (int*) malloc(s->capacity * sizeof(int));
    s->top = -1;
    while (1)
    {
        printf("\nEnter,\n1.PUSH\n2.POP\n3.PEEK\n4.Show Top\n5.Show Bottom\n6.Show\n7.Exit: ");
        scanf("%d", &option);
        if (option == 1) push(s);  
        else if (option == 2) pop(s);
        else if (option == 3) peek(s);
        else if (option == 4) show_top(s);
        else if (option == 5) show_bottom(s);
        else if (option == 6) show(s);
        else{
            free(s->a);
            break;
        };
    }
    return 0;
}