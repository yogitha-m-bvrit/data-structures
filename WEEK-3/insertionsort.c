#include<stdio.h>
void inserionsort(inta[100],int n)
{
           int i,j,index;
           for(i=1;i<n;i++)
           {
                      index=a[i];
                      j=1;
                      while(j>0)&&(a[j-1]>index))
                      {                 
                                a[j]=a[j-1];
                                j=j-1;
                      }
                      a[j]=index;
           }
}
int main()
{
           int n,i;
           scanf("%d",&n);
           int a[n];
           for(i=0;i<n;i++)
           {
                       scanf("%d",&a[i]);
           }
           insertionsort(a,n);
           printf("elements after sorting:\n");
           for(i=0;i<n;i++)
           {
                      printf("%d\n",[i]);
           }
}