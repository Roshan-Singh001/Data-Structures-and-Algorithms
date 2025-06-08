#include <stdio.h>
#include <stdlib.h>

//Node Definition
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
}lstnode;

//Traversel
void show(lstnode * head){
    lstnode * ptr = head;
    do
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

//Insertion in Circular Doubly Linked List

//1. At First Position
lstnode * atfirst(lstnode * head, int data){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    lstnode * p = head;
    ptr->data = data;
    do
    {
        p = p->next;
    } while (p->next != head);
    p->next = ptr;
    ptr->next = head;
    ptr->prev = p;
    head->prev = ptr;
    head = ptr;
    return head;
}

//2. At Last Position
lstnode * atlast(lstnode * head, int data){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    lstnode * p = head;
    ptr->data = data;
    do
    {
        p = p->next;
    } while (p->next != head);
    ptr->next = head;
    ptr->prev = p;
    p->next = ptr;
    head->prev = ptr;
    return head;
}

//Deletion in Circular Doubly Linked List

//1. From Beginning
lstnode * delF(lstnode * head){
    lstnode * p = head;
    lstnode * q = head->next;
    lstnode * r = head;
    do
    {
        r = r->next;
    } while (r->next != head);
    r->next = q;
    q->prev = r;
    head = q;
    free(p);
    return head;
}

//2. From Last
lstnode * delL(lstnode * head){
    lstnode * p = NULL;
    lstnode * q = head;
    do
    {
        q = q->next;
    } while (q->next != head);
    p = q->prev;
    p->next = head;
    head->prev = p;
    free(q);    
    return head;
}



int main()
{
    lstnode * head = (lstnode*) malloc(sizeof(lstnode));
    head->data = 1;
    head->prev = head;
    head->next = head;

    //Insetion
    printf("\nInsertion\n");
    head = atfirst(head,2);
    show(head);
    head = atfirst(head,4);
    show(head);
    head = atfirst(head,7);
    show(head);
    head = atlast(head,5);
    show(head);

    //Deletion
    printf("\nDeletion\n");
    head = delF(head);
    show(head);
    head = delL(head);
    show(head);
    
    return 0;
}