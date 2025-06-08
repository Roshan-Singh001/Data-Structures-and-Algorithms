#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A+(B*C-(D/E^F)*G)*H

int top = -1;
int capacity;

void show(int a[])
{
    printf("\n");
    printf("\n--> %c", a[top]);
    for (int i = top - 1; i >= 0; i--)
    {
        printf("\n    %c", a[i]);
    }
}

void push(int a[], char val)
{
    top++;
    a[top] = val;
}

char pop(int a[])
{
    char ch = a[top];
    top--;
    return ch;
}

int main()
{
    int length;
    printf("Enter the length of the expression: ");
    scanf("%d", &length);
    capacity = length;
    int a[length];
    char *infix = (char *)malloc((length + 3) * sizeof(char));
    char *postfix = (char *)malloc((length + 3) * sizeof(char));
    getchar();
    printf("Infix Expression: ");
    gets(infix);
    int i = 0, j = 0;
    infix[strlen(infix)] = '\0';
    push(a, '(');
    // show(a);
    // printf("\nsize = %d",strlen(infix));
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(a, '(');
            i++;
        }
        else if (infix[i] == ')')
        {
            while (a[top] != '(')
            {
                if (a[top] != ')')
                {
                    postfix[j] = pop(a);
                    j++;
                }
                else
                {
                    pop(a);
                }
            }
            pop(a);
            j++;
            i++;
            continue;
        }
        else if (infix[i] > 64 && infix[i] <= 90)
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            push(a, infix[i]);
            i++;
        }
    }
    push(a, ')');
    // show(a);
    while (a[top] != '(')
    {
        if (a[top] != ')')
        {
            postfix[j] = pop(a);
            j++;
            
        }
        else
        {
            pop(a);
        }
    }
    pop(a);
    printf("\n");
    for (int i = 0; i < j; i++)
    {
        printf("%c",postfix[i]);
    }
    free(infix);
    free(postfix);
    return 0;
}