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
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//Insertion in Linked List

//1. At first position
lstnode * atfirst(lstnode * head, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    p->next = head;
    head = p;
    return head;
}

//2. At last Position
lstnode * atlast(lstnode * head, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    while (ptr->next != NULL)       
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = NULL;
    return head;
}

//3. After a given node
lstnode * afternode(lstnode * head, lstnode * afnode, int data){
    lstnode * ptr = head;
    lstnode * p = (lstnode*) malloc(sizeof(lstnode));
    p->data = data;
    p->next = afnode->next;
    afnode->next = p;
    return head;
}

//4. At given index
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

//Deletion in Linked List

//1. Of first Node
lstnode* delF(lstnode * head){
    lstnode * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//2. Of last Node
lstnode * delL(lstnode * head){
    lstnode * ptr = head;
    lstnode * p = head;
    while (ptr->next != NULL) ptr = ptr->next;
    while (p->next != ptr) p = p->next;
    p->next = NULL;
    free(ptr);
    return head;
}

//3. Of a Given Node
lstnode * delM(lstnode * head){
    lstnode * ptr = head;
    int node = 1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        node++;
    }
    ptr = head;
    int mid = node/2;
    for (int i = 1; i < mid; i++)
    {
        ptr = ptr->next;
    }
    lstnode * q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

//4. Of a Node with a given data
lstnode * delD(lstnode * head, int data){
    lstnode * ptr = head;
    if (ptr->data == data)
    {
        head = head->next;
        free(ptr);
        return head;
    }
    else
    {
        lstnode * p = ptr->next;
        while (p->data != data && p->next != NULL)
        {
            ptr = ptr->next;
            p = p->next;
        }
        if (p->data != data)
        {
            printf("\nNot found\n");
            return head;
        }
        else
        {
            ptr->next = p->next;
            free(p);
            return head;
        }
    }
}

int main()
{
    lstnode * head = (lstnode*) malloc(sizeof(lstnode));
    head->data = 1;
    head->next = NULL;

    //Insertion
    head = atfirst(head,2);
    head = atlast(head,3);
    head = afternode(head,head,4);
    head = atindex(head,5,3);
    show(head);

    //Deletion
    head = delF(head);
    show(head);
    head = delL(head);
    show(head);
    head = delM(head);
    show(head);
    head = delD(head,5);
    show(head);

    return 0;
}