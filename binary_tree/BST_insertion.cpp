#include<iostream>
using namespace std;

class Node{
    public:
    int info; 
    Node *left;
    Node *right;
    Node(int data)
    {
        info=data;
        left=NULL;
        right=NULL; 
    }
};

class Solution{
    public:
    Node *insert(Node *root,int data)
    {
        Node *ptr=root;
        Node *tmp=new Node(data);
        if(root==NULL)
        {
            root=tmp;
            return root;

        }
        else
        {
            if(data < ptr->info)
            ptr->left=insert(ptr->left,data);
            else if(data > ptr->info)
            ptr->right=insert(ptr->right,data);
            else
            cout<<"Duplicate key not allowed"<<endl;
        }
        return root;
    }
};

int main()
{
    Solution s;
    Node *root=NULL;
    int n,element;
    cout<<"Number of elements to be inserted : ";
    cin>>n;
    cout<<"Enter "<<n<<" elements to be inserted :"<<endl;
    while(n--)
    {
        cin>>element;
        root=s.insert(root,element);
    }
    return 0;
}