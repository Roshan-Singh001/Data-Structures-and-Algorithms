#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;

} stack;

void show(stack *ptr)
{
    if (ptr != NULL)
    {
        printf("\n-->%d\n",ptr->data);
        ptr = ptr->next;
        while (ptr != NULL)
        {
            printf("   %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
    else printf("\nNothing To Show :/\n");
}

stack *push(stack *top, int data)
{
    stack *node = (stack *)malloc(sizeof(stack));
    if (node == NULL) printf("\nStack Overflow\n");
    else
    {
        node->data = data;
        node->next = top;
        top = node;
        return top;
    }
}

stack *pop(stack * top){
    if (top == NULL) printf("\nStack Underflow\n");
    else
    {
        stack * p = top;
        top = top->next;
        free(p);
        return top;
    }
}

int main()
{
    stack *top = NULL;
    top = push(top, 1);
    show(top);
    top = push(top, 2);
    show(top);

    top = pop(top);
    show(top);
    top = pop(top);
    show(top);

    top = pop(top);
    show(top);

    top = push(top, 1);
    show(top);
    top = push(top, 2);
    show(top);

    return 0;
}