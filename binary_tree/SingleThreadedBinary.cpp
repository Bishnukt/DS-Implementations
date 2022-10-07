#include<iostream>
using namespace std;

class Node{
    int info;
    Node *left,*right;
    bool isThreaded;
    friend class BinaryTree;
    public:
    Node(int data):info(data),left(NULL),right(NULL),isThreaded(false){}
};
class BinaryTree{
    public:
    Node* insert(Node *root,int data)
    {
        Node *ptr=root;
        if(root==NULL)
        {
            Node *tmp = new Node(data);
			tmp->isThreaded=true;
			return tmp;

        }
        if(data<ptr->info)
        {
			if(ptr->left==NULL)
			{
				Node *par=ptr;
            	ptr->left=insert(ptr->left,data);
				ptr->left->right=par;
			}
			else
				ptr->left=insert(ptr->left,data);
        }
        else if(data==ptr->info)
        {
            cout<<"Duplicate keys not allowed."<<endl;
            return root;
        }
        else
        {
			if(ptr->isThreaded)
			{
				Node *par=ptr->right;
				ptr->right=NULL;
				ptr->isThreaded=false;
				ptr->right=insert(ptr->right,data);
				ptr->right->right=par;
			}
			else
				ptr->right=insert(ptr->right,data);
		}
		return root;
	}

	void inorder(Node *root)
	{
		if(root==NULL)
		{
			cout<<"Tree is empty."<<endl;
			return;
		}
		Node *ptr=root;
		while(ptr->left!=NULL)
			ptr=ptr->left;
		while(ptr!=NULL)
		{
			cout<<ptr->info<<" ";
			if(ptr->isThreaded)
			{
				ptr=ptr->right;
			}
			else
			{
				ptr=ptr->right;
				if(ptr==NULL)
					return;
				while(ptr->left!=NULL)
					ptr=ptr->left;
			}
		}
	}
};
int main()
{
	BinaryTree a;
	Node *root=NULL;
	int choice,n,data;
	while(1)
	{
		cout<<"1.Insert\n2.Inorder Traversal of Threaded tree.\n3.Delete\n4.Exit"<<endl;
		cout<<"Enter your choice- ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Number of elements to insert- ";
				cin>>n;
				cout<<"Enter "<<n<<" integers :"<<endl;
				for(int i=0;i<n;i++)
				{
					cin>>data;
					root=a.insert(root,data);
				}
				break;

			case 2:
				a.inorder(root);
				cout<<endl;
				break;

			case 3:
				cout<<"\nFeature not available now"<<endl;
				break;

			case 4:
				exit(0);

			default: cout<<"Invalid choice. Try again."<<endl;
		}
	}
	return 0;
}
