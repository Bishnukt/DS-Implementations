//Implementing Stack using dynamic array
#include<iostream>
using namespace std;

class Solution{
    int Size=10;
    int *stack=new int[Size];
    int top=-1;
    public:
    void push(int data)
    {
        if(top==Size-1)
        {
            stack=(int *)realloc(stack,(Size+Size)*sizeof(int));
            if(stack==NULL)
            {
            cout<<"Stack overflow. Task failed.";
            return;
            }
            Size+=Size;
        }
        top++;
        *(stack+top)=data;
    }

    int pop()
    {
        int item;
        if(top<0)
        {
            cout<<"Stack underflow. Task failed.";
            return -1;
        }
        item=*(stack+top);
        top--;
        return item;
    }

    void display()
    {
        int i;
        if(top<0)
        {
            cout<<"Stack is empty.";
            return;
        }
        cout<<"\nElements present in the stack are : ";
        for(i=top;i>=0;i--)
        cout<<*(stack+i)<<" ";
    }
};
 
int main()
{ 
    Solution stack;
    int i,choice,data;
    while(1)
    {
    cout<<"\n1.Push.\n";
    cout<<"2.Pop.\n";
    cout<<"3.Display\n";
    cout<<"4.Exit.\n";
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"Enter the element to be pushed: ";
        cin>>data;
        stack.push(data);
        break;

        case 2:
        data=stack.pop();
        if(data!=-1)
        cout<<data<<" popped out of the stack.";
        break;

        case 3:
        stack.display();
        break;

        case 4:
        exit(1);

        default: cout<<"Invalid choice. Try again.\n";
    }
    }
    return 0;
}
