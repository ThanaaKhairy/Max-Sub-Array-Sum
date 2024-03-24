#include <stdio.h>
#include <stdlib.h>

int MaxSubArraySum(int array[],int start,int end);

int MaxCrossingSubArray(int array[],int start,int center,int end);

int MaxElement(int array[],int size);

int main()
{
int x,y,MaxSum;

   printf("enter the size of the array ");

   scanf("%d",&x);

   int arr[x];

   for(int i=0;i<x;i++)
   {
       printf("enter the value ");
       scanf("%d",&arr[i]);
   }
int MaxNumber=MaxElement(arr,x);

 if(MaxNumber<=0)
 {
     printf("the max sub array sum is: %d",MaxNumber);
 }
 else
 {
MaxSum=MaxSubArraySum(arr,0,x-1);
printf("the max sub array sum is: %d",MaxSum);

 }
    return 0;
}


int MaxElement(int array[],int size)
{
    int Max=array[0];

  for(int i=1;i<size;i++)
   {
       if(array[i]>Max)
       {
           Max=array[i];
       }
   }
   return Max;
}

int MaxSubArraySum(int array[],int start,int end)
{
    if(start==end)
    {
        return array[start];
    }
    else
    {
      int center=(start + end)/2;

      int left=MaxSubArraySum(array,start,center);

      int crossing=MaxCrossingSubArray(array,start,center,end);

      int right=MaxSubArraySum(array,center+1,end);

      if((right > left)&&(right > crossing))
      {
          return right;
      }
      else if((left > right)&&(left > crossing))
      {
          return left;
      }
      else
      {
          return crossing;
      }
    }
}


int MaxCrossingSubArray(int array[],int start,int center,int end)
{
    int LeftMaxSum=-4294967295;
    int rightMaxSum=-4294967295;
    int sum=0;
    for(int i=center+1;i<=end;i++)
    {
        sum=sum+array[i];
        if(sum > rightMaxSum)
        {
            rightMaxSum=sum;
        }
    }

     sum=0;
    for(int i=center;i >= start;i--)
    {
        sum=sum+array[i];
        if(sum > LeftMaxSum)
        {
            LeftMaxSum=sum;
        }
    }
    int FinalSum=LeftMaxSum+rightMaxSum;

    return FinalSum;
}


