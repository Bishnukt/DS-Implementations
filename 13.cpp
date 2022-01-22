//Implementing Stack using linked list
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
    Node *top=NULL;
    public:
    void push(int data)
    {
        if(top==NULL)
        {
            top=new Node(data);
            if(top==NULL)
            {
                cout<<"Stack overflow."<<endl;
            }
            return;
        }
        Node *tmp=new Node(data);
        if(tmp==NULL)
        {
            cout<<"Stack underflow."<<endl;
            return;
        }
        tmp->next=top;
        top=tmp;
    }

    int pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow."<<endl;
            return -1;
        }
        int popped=top->info;
        Node* tmp=top;
        top=top->next;
        free(tmp);
        return popped;
    }

    void display()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty."<<endl;
            return;
        }
        Node *tmp=top;
        cout<<"Elements present in the stack are: ";
        while(tmp!=NULL)
        {
            cout<<tmp->info<<" ";
            tmp=tmp->next;
        }
    }
};

int main()
{
    Solution stack;
    int data;
    while(1)
    {
    cout<<"\n1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl<<"Enter your choice : ";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"Enter the element to be inserted : ";
        cin>>data;
        stack.push(data);
        cout<<endl;
        break;

        case 2:
        data=stack.pop();
        if(data!=-1)
        cout<<"Popped item is : "<<data<<endl;
        break;

        case 3:
        stack.display();
        cout<<endl;
        break;

        case 4:
        cout<<endl;
        exit(0);

        default:cout<<"Invalid choice.Try again."<<endl;
    }
    }
return 0;
}