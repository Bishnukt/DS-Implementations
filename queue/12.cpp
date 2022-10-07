//Implementing Queue using dynamic array
#include<iostream>
using namespace std;
#define size 10
class Solution{
    int front=-1,rear=-1;
    int *queue=new int[size];
    public:
    void enqueue(int data)
    {
        if(front==-1)
        {
        front++;
        *(queue+front)=data;
        rear=front;
        return;
        }
        else if(rear==size-1)
        {
            cout<<"Queue overflow. Task failed."<<endl;
            return;
        }
        rear++;
        *(queue+rear)=data;
    }
    
    int dequeue()
    {
        if(front==-1 || front==rear+1)
        {
            cout<<"Queue underflow. Queue is empty."<<endl;
            return -1;
        }
        int temp=*(queue+front);
        front++;
        return temp;
    }

    void display()
    {
        if(front==-1 || front==rear+1)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
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