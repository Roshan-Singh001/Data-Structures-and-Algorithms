#include <stdio.h>
#include <stdlib.h>

//Node Definition
typedef struct Node
{
    int data;
    struct Node *next;
}lstnode;

//Traversel
void show(lstnode *head){
    lstnode *p = head;
    do
    {
        printf("%d ",p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

//Insertion in Circular Linked List

//1. At first position
lstnode * atfirst(lstnode * head, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = p;
    p->next = head;
    head = p;
    return head;
}

//3. At last position
lstnode * atlast(lstnode * head, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = p;
    p->next = head;
    return head;
}

lstnode * afternode(lstnode * head, lstnode * afnode, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    p->next = afnode->next;
    afnode->next = p;
    return head;
}

lstnode * atindex(lstnode * head, int data, int index){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    int i = 1;
    p->data = data;
    while (i != index-1)
    {
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;
}

//Deletion in Circular Linked List

//1.From beginning
lstnode * delF(lstnode * head){
    lstnode * p = head;
    lstnode * ptr = head;
    do
    {
        ptr = ptr->next;
    } while (ptr->next != head);
    head = head->next;
    ptr->next = head;
    free(p);
    return head;
}

//2. From Last
lstnode * delL(lstnode * head){
    lstnode * p = head;
    lstnode * q = head;
    do
    {
        p = p->next;
    } while (p->next != head);
    while(q->next != p){
        q = q->next;
    }
    q->next = head;
    free(p);
    return head;
}


int main()
{
    lstnode * head = (lstnode*) malloc(sizeof(lstnode));
    head->data = 1;
    head->next = head;

    //Insertion
    printf("\nInsertion\n");
    head = atfirst(head,2);
    show(head);
    head = atlast(head,3);
    show(head);
    head = afternode(head,head,56);
    show(head);
    head = atindex(head,67,3);
    show(head);

    //Deletion
    printf("\nDeletion\n");
    head = delF(head);
    show(head);
    head = delL(head);
    show(head);

    return 0;
}