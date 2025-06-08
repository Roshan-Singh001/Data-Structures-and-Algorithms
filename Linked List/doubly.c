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
void show(lstnode *head){
    lstnode *p = head;
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//Insertion in Doubly Linked List

//1. At First Position
lstnode * atfirst(lstnode * head, int data){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}

//2. At Lat Position
lstnode * atlast(lstnode * head, int data){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    lstnode * p = head;
    ptr->data = data;
    ptr->next = NULL;
    while (p->next != NULL) p = p->next;
    ptr->prev = p;
    p->next = ptr;
    return head;
}

//3. After a Given Node
lstnode * afternode(lstnode * head, lstnode * afn, int data){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    lstnode * p = NULL;
    ptr->data = data;
    p = afn->next;
    ptr->next = p;
    ptr->prev = afn;
    afn->next = ptr;
    p->prev = ptr;
    return head;
}

//4. At a given Index
lstnode * atindex(lstnode * head, int data, int index){
    lstnode * ptr = (lstnode*) malloc(sizeof(lstnode));
    lstnode * p = head;
    lstnode * q = NULL;
    int i = 0;
    ptr->data = data;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    ptr->next = q;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;
    return head;
}

//Deletion in Doubly Linked List

//1. From Beginning
lstnode * delF(lstnode * head){
    lstnode * p = head;
    head = head->next;
    free(p);
    return head; 
}

//2. From Last
lstnode * delL(lstnode * head){
    lstnode * p = head;
    lstnode * q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head; 
}

//3. Of a given Node
lstnode * delM(lstnode * head){
    lstnode * p = head;
    lstnode * q = NULL;
    lstnode * r = NULL;
    int node = 1;
    while (p->next != NULL)
    {
        p = p->next;
        node++;
    }
    p = head;
    int mid = node/2;
    for (int i = 1; i < mid; i++) p = p->next;
    r = p->next;
    q = p->prev;
    q->next = p->next;
    r->prev = q;
    free(p);
    return head;
}

int main()
{
    lstnode * head = (lstnode*) malloc(sizeof(lstnode));
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;

    //Insertion
    printf("\nInsertion\n");
    head = atfirst(head,2);
    show(head);
    head = atlast(head,34);
    show(head);
    head = afternode(head,head,88);
    show(head);
    head = atindex(head,56,3);
    show(head);

    //Deletion
    printf("\nDeletion\n");
    head = delF(head);
    show(head);
    head = delL(head);
    show(head);
    head = delM(head);
    show(head);    
    return 0;
}