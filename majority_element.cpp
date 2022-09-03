//Using Boyer-Moore majorty voting algorithm
//Time complexity- O(n), space complexity- O(1).

#include<iostream>
using namespace std;

int solve(int *arr,int n)
{
	int ans_ind=0,count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[ans_ind]==arr[i])
			count++;
		else
		{
			count--;
			if(count==0)
			{
				ans_ind=i;
				count++;
			}
		}
	}

	if(count>0)
	{
		count=0;
		for(int i=0;i<n;i++)
			if(arr[ans_ind]==arr[i])
				count++;
		if(count>n/2)
			return ans_ind;
	}

	return -1;
}

int main(int argc,char *argv[])
{
	int n;
	if(argc>1)
		n=atoi(argv[1]);
	else
	{
		cout<<"Enter the no. of elements: ";
		cin>>n;
	}

	int *arr=new int[n];

	printf("Enter elements: ");
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int res=solve(arr,n);
	if(res==-1)
		cout<<"No majority element in given array.\n";
	else
		cout<<arr[res]<<" is the majority element in the given array."<<endl;

	return 0;
}
