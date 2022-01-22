//Implementing 2D Dynamic array
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r,c,i,j;
    printf("Enter the number of row and column :\n");
    scanf("%d %d",&r,&c);
    int **ptr=(int **)malloc(r*sizeof(int *));
    for(i=0;i<r;i++)
    {
        ptr[i]=(int *)malloc(c*sizeof(int));
    }
    printf("Enter %d elements : \n",r*c);
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        scanf("%d",ptr[i]+j);
    }

    printf("Elemnts present in the array are :\n");
    for(i=0;i<r;i++)
    {
    for(j=0;j<c;j++)
    {
        printf("%d ",*(ptr[i]+j));
    }
    printf("\n");
    }  
    return 0;  
}