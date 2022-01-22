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
    void preorder(Node *root)
    {
        if(root!=NULL)
        {
            cout<<" "<<root->info;
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(Node *root)
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<" "<<root->info;
        }
    }
    void inorder(Node *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<" "<<root->info;
            inorder(root->right);
        }
    }
};

int main()
{
    Solution sol;
    Node *ptr=new Node(1);
    ptr->left=new Node(2);
    ptr->right=new Node(3);
    ptr->left->left=new Node(4);
    ptr->left->right=new Node(5);
    ptr->right->left=new Node(6);
    ptr->right->right=new Node(7);
    cout<<"Preorder Traversal: ";
    sol.preorder(ptr);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    sol.postorder(ptr);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    sol.inorder(ptr);
    cout<<endl;
    return 0;

}