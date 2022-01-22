//One dimensional dynamic array implementation

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int s,*ptr,i;
    printf("Enter the number of elements to enter : ");
    scanf("%d",&s);
    ptr=(int *)malloc(sizeof(int));
    printf("Enter %d elements :\n",s);
    for(i=0;i<s;i++)
    {
        printf("%d ",*(ptr+i));
    }
    return 0;
}