#include<iostream>
using namespace std;

class Node{
protected:
	char info;
	Node *next;
public:
	Node(char data)
	{
		info=data;
		next=NULL;
	}
};
class Solution{
private:
	Node *top=NULL;
public:

	void push(char data);
	{
		if(top==NULL)
		{
			top=new Node(data);
			
		}
		Node *tmp=New Node(data);
		tmp->next=top;
		top=tmp;
	}
	char pop()
	{
		if(top==NULL)
		{
			cout<<"Stack Underflow."<<endl:
			return;
		}
		Node *tmp=top;
		char popped=top->info;
		top=top->next;
		free(tmp);
		return popped;
	}
}

int main()
{
	String s;
	Solution stack;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		while(s[i]!=')')
		{
		if(s[i]>=48 && s[i]<=57)
		{

		}

	}
}