#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,y,sum,maxsum;
   printf("enter the size of the array ");
   scanf("%d",&x);
   y=5*x;
   int arr[x];
   int sumArr[y];


   for(int i=0;i<x;i++)
   {
       printf("enter the value ");
       scanf("%d",&arr[i]);
   }

int Max1=arr[0];

 for(int i=1;i<x;i++)
   {
       if(arr[i]>Max1)
       {
           Max1=arr[i];
       }
   }

   y=0;

  for(int i=0;i<x-1;i++)
   {
    if(arr[i]>0)
    {
    sum=arr[i];
      for(int j=i+1;j<x;j++)
       {
          sum=sum+arr[j];
          sumArr[y]=sum;
          y++;
       }
    }
   }
int Max2=sumArr[0];

  for(int i=1;i<y;i++)
   {

              if(sumArr[i]>Max2)
       {
           Max2=sumArr[i];
       }
   }


    if((Max1>Max2)|| y==0)
   {

       printf("the max sub array sum is:%d",Max1);

   }
   else
   {

       printf("the max sub array sum is:%d",Max2);

   }
    return 0;
}









