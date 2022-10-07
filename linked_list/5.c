//Implementing single linked list with associated operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *);
struct node *addat_end(struct node*,int);
struct node *addat_beg(struct node*,int);
struct node *addat_pos(struct node*,int,int);
struct node *delete(struct node*,int);
void search(struct node*,int);
void display(struct node *);

int main()
{
    int choice,data,pos;
    struct node *start=NULL;
    while(1)
    {
    printf("\n1.Create list.\n");
    printf("2.Insert at end.\n");
    printf("3.Insert at beginning.\n");
    printf("4.Insert at position.\n");
    printf("5.Search.\n");
    printf("6.Delete.\n");
    printf("7.Display.\n");
    printf("8.Exit.\n");
    printf("Enter your choice- ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
    start=create_list(start);
    break;

    case 2:
    printf("Enter the element to be inserted at end: ");
    scanf("%d",&data);
    start=addat_end(start,data);
    break;

    case 3:
    printf("Enter the element to be inserted at beginning : ");
    scanf("%d",&data);
    start=addat_beg(start,data);
    break;

    case 4:
    printf("Enter the position to insert : ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted at position %d : ",pos);
    scanf("%d",&data);
    start=addat_pos(start,data,pos);
    break;

    case 5:
    printf("Enter the element to search in the list : ");
    scanf("%d",&data);
    search(start,data);
    break;

    case 6:
    printf("Enter the element to delete from the list : ");
    scanf("%d",&data);
    start=delete(start,data);
    break;

    case 7:
    display(start);
    break;

    case 8:
    exit(1);
    break;

    default:printf("Invalid choice, try again.\n");
    }
    getchar();
    printf("\nEnter any key to continue :");
    getchar();
    }
    return 0;

}
struct node *create_list(struct node *start)
{
    int size,data,i;
    printf("How many elements you want to add : ");
    scanf("%d",&size);
    if(start==NULL)
    {
        printf("Enter %d elements:",size);
        scanf("%d",&data);
        start=(struct node *)malloc(sizeof(struct node));
        start->info=data;
        start->link=NULL;
        for(i=0;i<size-1;i++)
        {
            scanf("%d",&data);
            start=addat_end(start,data);
        }
        printf("List created.\n");
        return start;
    }
    printf("List already exists. Inserting data at the end.\n");
    start=addat_end(start,data);
    return start;
}

struct node *addat_end(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        start=(struct node *)malloc(sizeof(struct node));
        printf("New node added.\n");
        start->info=data;
        start->link=NULL;
        return start;
    }
    struct node *ptr=start,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=tmp;
    tmp->link=NULL;
    return start;
}

struct node *addat_beg(struct node *start,int data)
{
    if(start==NULL)
    {
    printf("The list in empty.");
    start=(struct node *)malloc(sizeof(struct node));
    start->info=data;
    start->link=NULL;
    printf("List created and element added at the beginning.\n");
    return start;
    }
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=start;
    start=tmp;
    return start;
}

struct node *addat_pos(struct node *start,int data,int pos)
{
    if(start==NULL)
    {
        printf("The list is empty. Task failed.\n");
        return start;
    }
    else if(pos==1)
    {
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
    }
    else
    {
        struct node *ptr=start;
        struct node *tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;        
        int i;
        
        for(i=1;i<pos-1 && ptr->link!=NULL;i++)
        ptr=ptr->link;
        if(ptr->link==NULL)
        {
            printf("Position exceeds the size of list.\n");
            return start;
        }
        tmp->link=ptr->link;
        ptr->link=tmp;
        return start;
    }
}

struct node *delete(struct node *start,int data)
{
    struct node *ptr=start,*tmp;
    if(start->info==data)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return start;
    }
    while(ptr->link!=NULL)
    {
        if(ptr->link->info==data)
        {
            tmp=ptr->link;
            ptr->link=ptr->link->link;
            free(tmp);
            return start;
        }
        ptr=ptr->link;
    }
    printf("%d not found in the list.\n",data);
    return start;
}

void display(struct node *start)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr=start;
    printf("Elements present in the list are- ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
}

void search(struct node *start,int data)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr=start;
    int count=1;
    while(ptr!=NULL)
    {
        if(ptr->info==data)
        {
            printf("%d found at position number %d.\n",data,count);
            return;
        }
        ptr=ptr->link;
        count++;
    }
    printf("%d not found in the list.\n",data);
}