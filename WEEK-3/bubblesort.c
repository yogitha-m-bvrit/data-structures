#include<stdio.h>
void bubblesort(int a[100],int n)
{
        int i,j,t;
        for(i=0;i<n-i-1;j++)
        {
                  for(j=0;j<n-i-1;j++)
                  {
                              if(a[j]>a[j+1])
                              {         
                                          t=a[j];
                                          a[j]=a[j+1];
                                          a[j+1]=t;
                              }
                  }
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
           bubblesort(a,n);
           printf("elements after sorting:\n");
           for(i=0;i<n;i++)
           {
                      printf("%d\n",a[i]);
}