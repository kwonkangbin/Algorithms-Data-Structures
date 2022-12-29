#include <stdio.h>
int main()
{
    int i,j,n=4,temp;
    int list[4]={4,5,1,2};

    for(i=n-1; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(list[j]>list[j+1])
            {
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}
