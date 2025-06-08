#include <stdio.h>
#include <stdlib.h>

int Hash_function(int data, int size){
    return data % size;
}

void insert(int *hash, int data, int size, int index){
    if (hash[index] != 0)
    {
        if (hash[index] == data)
        {
            printf("\n---> %d is already inserted <---", data);
        }
        else
        {
            printf("\n---> Nikal <---\n");
        }
    }
    else
    {
        hash[index] = data;
    }
}


void display(int *hash, int size){
    printf("\nIndex \tData\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d \t%d\n",i,hash[i]);
    }
}

int main()
{
    int choice, size;
    int *hash;
    printf("\n---\tHashing\t---\n");
    while (1)
    {
        printf("\nEnter,\n");
        printf("1.Create Hash Table\n");
        printf("2.Insert\n");
        printf("3.Remove\n");
        printf("4.Search\n");
        printf("5.Display\n");
        printf("6.Exit: ");
        scanf("%d",&choice);

        if (choice == 1)
        {
            printf("Enter size of the Hash Table: ");
            scanf("%d",&size);

            hash = (int *) malloc(size * sizeof(int));
            if (hash)
            {
                printf("\n---> Hash Table is created <---\n");
                for (int i = 0; i < size; i++) hash[i] = 0;
            }
            else
            {
                printf("\n---> Error Occured <---");
            }
        }
        else if(choice == 2)
        {
            int data;
            printf("\nEnter a element: ");
            scanf("%d", &data);
            int index = Hash_function(data,size);
            insert(hash,data,size,index);
            
        }
        else if (choice == 3){
            //Remove
        }
        else if (choice == 4)
        {
            //Search
        }
        else if (choice == 5)
        {
            display(hash,size);
        }
        else if(choice == 6){
            free(hash);
            break;
        }
        else
        {
            printf("\n~~ Invalid Input ~~\n");
        }
    }
    

    return 0;
}