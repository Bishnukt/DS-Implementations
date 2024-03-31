#include <stdio.h>
#include <stdlib.h>

#define size 5
// int size;

struct node
{
    int val;
    struct node *next;
};

struct node **table = NULL;

void hashTable()
{
    table = (struct node **)malloc(sizeof(struct node *) * size);
    for (int i = 0; i < size; i++)
    {
        table[i] = NULL;
    }
}

int generateHash(int val)
{
    val = abs(val);
    int hashKey = val % size;
    return hashKey;
}

void insert(int val)
{
    int hashKey = generateHash(val);
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    if (table[hashKey] == NULL)
    {
        table[hashKey] = tmp;
        return;
    }

    printf("Collision occurred at index %d.\n", hashKey);

    struct node *ptr = table[hashKey];

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = tmp;
}

int delete(int val)
{
    int hashKey = generateHash(val);
    if (table[hashKey] == NULL)
    {
        return -1;
    }

    if (table[hashKey]->val == val)
    {
        struct node *tmp = table[hashKey];
        table[hashKey] = table[hashKey]->next;
        free(tmp);
        return 1;
    }

    struct node *ptr = table[hashKey];
    struct node *prev = NULL;

    while (ptr != NULL && ptr->val != val)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return -1;
    }
    struct node *tmp = ptr;
    prev->next = ptr->next;
    free(tmp);
    return 1;
}

int search(int val)
{
    int hashKey = generateHash(val);
    if (table[hashKey] == NULL)
    {
        return -1;
    }

    struct node *ptr = table[hashKey];

    while (ptr != NULL)
    {
        if (ptr->val == val)
        {
            return 1;
        }
        ptr = ptr->next;
    }
    return -1;
}

void print()
{
    for(int i=0;i<size;i++){
        if(table[i] == NULL){
            printf("NULL\n");
        }
        else{
            struct node *ptr = table[i];
            while(ptr!=NULL){
                printf("%d-->",ptr->val);
                ptr = ptr->next;
            }
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    // printf("Enter the size of the hashtable- ");
    // scanf("%d", &size);
    hashTable();

    printf("Inserting- 5,13,11,20,21\n\n");

    insert(5);
    insert(13);
    insert(11);
    insert(20);
    insert(21);
    print();

    printf("Deleting- 5\n\n");
    delete(5);
    print();

    printf("Searching- 21\n\n");
    int found = search(21);
    if(found!=-1){
        printf("21 found\n\n");
    }
    print();

    return 0;




}