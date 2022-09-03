#include<stdio.h>
#include<stdlib.h>

struct node *addat_end(struct node *start,int data);
void display(struct node *start);
//void display_add(struct node *start);
struct node
{
    int info;
    struct node *link;
    struct node *prev;
};
void main()
{
    struct node *start=NULL;
    int data,i;
    do
    {
    printf("How many elements do you want to be added in the list?(Only positive integer>0 acceptable.)\n");
    scanf("%d",&i);
    } while (i<=0);
    
    printf("Enter %d elements to be added in the list : \n",i);
    while(i>0)
    {
    scanf("%d",&data);
    start=addat_end(start,data);
    i--;
    }
    display(start);
//    display_add(start);
}

struct node *addat_end(struct node *start,int data)
{
    if(start==NULL)
    {
        start=(struct node *)malloc(sizeof(struct node));
        start->info=data;
        return start;
    }
    else
    {
    struct node *ptr=start,*tmp=(struct node*)malloc(sizeof(struct node));
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }   
    tmp->info=data;
    ptr->link=tmp;    
    tmp->link=NULL;
    tmp->prev=ptr;
    return start;
    }
}

void display(struct node *start)
{
    if(start==NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr=start;
    printf("Elements present in the list are : \n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
}

// void display_add(struct node *start)
// {
//     struct node *p=start;
//     while(p!=NULL)
//     {
//         printf("prev link = %p, next link=%p\n",p->prev,p->link);
//         p=p->link;
//     }
// }