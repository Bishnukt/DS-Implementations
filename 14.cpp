//Implementing Queue using linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int info;
    Node *next;
    Node(int info)
    {
        this->info=info;
        next=NULL;
    }
};

class Solution{
    Node *front=NULL,*rear=NULL;
    public:
    void enqueue(int data)
    {
        if(front==NULL)
        {
            front=new Node(data);
            rear=front;
            return;
        }
        rear->next=new Node(data);
        rear=rear->next;
    }

    int dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue underflow."<<endl;
            return -1;
        }
        Node *tmp=front;
        int dequeued=front->info;
        front=front->next;
        free(tmp);
        return dequeued;
    }

    void display()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        cout<<"Elements present in the list are: ";
        Node *ptr=front;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->next;
        }
    }
};

int main()
{
    Solution queue;
    int data;
    while(true)
    {
    cout<<"1.Enqueue."<<endl;
    cout<<"2.Dequeue."<<endl;
    cout<<"3.Display."<<endl;
    cout<<"4.Exit."<<endl;
    int choice;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1: 
    cout<<"Enter element to insert: ";
    cin>>data;
    queue.enqueue(data);
    cout<<endl;
    break;

    case 2:
    data=queue.dequeue();
    if(data!=-1)
    cout<<data<<" dequeued."<<endl;
    cout<<endl;
    break;

    case 3:
    queue.display();
    cout<<endl;
    break;

    case 4:
    cout<<endl;
    exit(0);
    
    default:cout<<"Invalid choice. Try again."<<endl;
    cout<<endl;
    }
    }
    return 0;
}