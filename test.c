#include<stdio.h>
struct node
{
    int value;
    struct node *next;
};
struct node *insertat_beg(struct node *, int data);
int main()
{
    struct node *start=NULL;
    int data;
    insertat_beg(start,data);
} 
struct node *insertat_beg(struct node *start,int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->value=data;
    if(start==NULL)
    {
        printf("The list is empty.");
        start=temp;
        start->next=NULL;
        printf("\nNew list created.");
        return start;

    }
    temp->next=start;
    start=temp;
    return start;
}
struct node *insertat_end(struct node *start, int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node ));
    if(start==NULL)
    {
        
    }
}
