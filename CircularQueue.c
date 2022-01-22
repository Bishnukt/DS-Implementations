#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(int);
int dequeue();
void display();

int main()
{
    int choice,element;
    while(1)
    {
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        printf("Enter the element to be enqueued. : ");
        scanf("%d",&element);
        enqueue(element);
        break;

        case 2:
        element=dequeue();
        printf("%d dequeued.\n", element);
        break;

        case 3:
        display();
        break;

        case 4:
        exit(0);

        default: printf("Invalid choice, try again.\n");
    }
    }

}

void enqueue(int item)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->next=front;
    if(front==NULL)
    front=tmp;
    else
    rear->next=tmp;
    rear=tmp;
}

int dequeue()
{
    if(front==NULL)
    {
        printf("Queue underflow. Task failed.\n");
        exit(1);
    }
    struct node *tmp=front;
    int item;
    front=front->next;
    rear->next=front;
    item=tmp->data;
    free(tmp);
    return item;
}

void display()
{
    if(front==NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node *ptr=front;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=front);
    printf("\n");
}