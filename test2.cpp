#include<iostream>
using namespace std;
int fun(int);
int main()
{
    int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}
int fun(int n)
{
    int count=0,count2=0;
    while(n/2!=1)
    {
        if(n%2==1)
        {
            count++;
        }
        else{
            if(count>count2)
            {
                count2=count;
                count=0;
            }
            count=0;
        }
        n=n/2;
    }
    if(n%2==0)
    {
        if(count>count2)
        {
            count2=count;
            count=1;
        }
        count=1;
    }
    else
        count=count+2;
        
    if(count>count2)
    return count;
    else
    return count2;
}