//Single Linked List Implementations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int item);
struct node *addat_beg(struct node *start,int data);
struct node *addat_end(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int data2);
struct node *addafter(struct node *start,int data,int data2);
struct node *delete(struct node *start,int data);
struct node *insert_at_pos(struct node *start,int data,int pos);
struct node *reverse(struct node *start);

void main()
{
    struct node *start=NULL;
    int data,data2,choice,pos;

    while(1)
    {
    printf("\n1.Create a list.\n");
    printf("2.Display.\n");
    printf("3.Count.\n");
    printf("4.Search.\n");
    printf("5.Add to empty list/Add at begining.\n");
    printf("6.Add at the end.\n");
    printf("7.Add after node.\n");
    printf("8.Add before node.\n");
    printf("9.Add at position.\n");
    printf("10.Delete.\n");
    printf("11.Reverse.\n");
    printf("12.Exit.\n\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        start=create_list(start);
        break;
        
        case 2:
        display(start);
        break;

        case 3:
        count(start);
        break;

        case 4:
        printf("Enter the element to be searched in the list : ");
        scanf("%d",&data);
        search(start,data);
        break;

        case 5:
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addat_beg(start,data);
        break;

        case 6:
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        start=addat_end(start,data); 
        break;

        case 7:
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        printf("Enter the element after which to insert : ");
        scanf("%d",&data2);
        start=addafter(start,data,data2);
        break;

        case 8:
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        printf("Enter the element before which to insert : ");
        scanf("%d",&data2);
        start=addbefore(start,data,data2);
        break;

        case 9:
        printf("Enter the element to be inserted : ");
        scanf("%d",&data);
        printf("Enter the position to insert : ");
        scanf("%d",&data2);
        insert_at_pos(start,data,data2);
        break;

        case 10:
        printf("Enter the element to delete from the list : ");
        scanf("%d",&data);
        start=delete(start,data);
        break;

        case 11:
        start=reverse(start);
        break;
        
        case 12:
        printf("Adios amigo :)\n");
        exit(1);

        default: printf("Wrong choice. Try again.\n\n"); 
    }
    }
}

struct node *create_list(struct node *start)
{
    start=(struct node*)malloc(sizeof(struct node));
    if(start!=NULL)
    {
        printf("List created.");
        return start;
    }
    printf("Memory allocation failed.\n");
    return start;
}

void display(struct node *start)
{
    if(start==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *p=start;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");
}

void count(struct node *start)
{
    if(start==NULL)
    {
        printf("The list is empty.");
    }
    struct node *p=start;
    int count=0;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    printf("Number of elements are - %d\n",count);
}


void search(struct node *start,int item)
{
    struct node *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->info==item)
        {
            printf("%d is found at position %d.\n",item,pos);
            return;
        }
        pos++;
    }
    printf("%d not found in list.",item);
}

struct node *addat_beg(struct node *start,int data)
{
    struct node *p;
    if(start!=NULL)
    {
    p=(struct node *)malloc(sizeof(struct node));
    p->info=data;
    p->link=start;    
    start=p;
    return start;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->info=data;
    p->link=NULL;
    start=p;
    return start;
}

struct node *addat_end(struct node *start,int data)
{
    struct node *p=start,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=tmp;
    tmp->link=NULL;
    return start;
}

struct node *addafter(struct node *start,int data,int data2)
{
    if(start==NULL)
    {
        printf("List is empty.\n");
        return start;
    }
    struct node *p=start;
    while(p->link!=NULL)
    {
        if(p->info==data2)
        {
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            return start;
        }
        p=p->link;
    }
    printf("%d not found in the list.\n",data2);
    return start;
}

struct node *addbefore(struct node *start,int data,int data2)
{
    int count=0;
    if(start!=NULL)
    {
        if(start->info==data2)
        {
            struct node *tmp=(struct node *)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=start;
            start=tmp;
            return start;
        }
        struct node *p=start;
        while(p->link!=NULL)
        {
            if(p->link->info == data2)
            {
                struct node *tmp=(struct node *)malloc(sizeof(struct node));
                tmp->info=data;
                printf("inserted data .\n");
                tmp->link=p->link;
                p->link=tmp;
                printf("tmp link stored in p");
                return start;
            }
            count++;
            printf("out of if loop %d\n",count);
            p=p->link;
        }
        printf("%d not found in the list.\n",data2);
    }
    printf("List is empty.\n");
    return start;
}

struct node *insert_at_pos(struct node *start,int data,int pos)
{
    if(start!=NULL)
    {
        int i=0;
        if(pos==0)
        {
            printf("Invalid position.\n");
            return start;
        }
        else if(pos==1)
        {
            struct node *tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=start;
            start=tmp;
            return start;
        }
        else
        {
        struct node *p=start;
        for(i=1;i<pos-1 && p!=NULL;i++)
        {
            p=p->link;
        }
            if(p==NULL)
            printf("Position exceeds the number of elements present\n");
            else
            {
                struct node *tmp=(struct node*)malloc(sizeof(struct node));
                tmp->info=data;
                tmp->link=p->link;
                p->link=tmp;
                return start;
            }
        }
    }
    printf("The list is empty.\n");
    return start;
}

struct node *delete(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        return start;
    }
    struct node *p=start;
    if(start->info==data)
    {
        struct node *tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    while(p->link!=NULL)
    {
        if(p->link->info == data)
        {
            struct node *tmp=p->link;
            p->link=p->link->link;
            free(tmp);
            return start;
        }
        p=p->link;
    }
    printf("Given element not found in the list.\n");
    return start;
}

struct node *reverse(struct node *start)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        return start;
    }
    struct node *ptr=start,*prev=NULL,*next=NULL;
    while(ptr!=NULL)
    {
        next=ptr->link;
        ptr->link=prev;
        prev=ptr;
        ptr=next;
    }
    start=prev;
    return start;
}