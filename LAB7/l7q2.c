#include <stdio.h>

// index determination 
int helper(int *x, int start, int n)
{
    int a=0,b=0;
    for(a=0;a<n;a++)
    {
        //element comparison 
        if(*(x+start)>*(x+a))
        {
            //update the posi
            b++;
        }
    }
    //return index 
    return b;
} 

int main()
{
    int n,start=0;
    int a,b;
    //get length
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int initial[n];
    int posi[n];
    int *x = initial;
    //user input
    printf("Enter 4 distinct positive integers: ");
    for (a=0;a<n; a++) 
    {
        scanf("%d",x++);
    }
    x = initial;
    //get the index posi and update
    while(start<=n-1)
    {
        b=helper(x,start,n);
        posi[b]=start;
        start++;
    }
    //output
    printf("Index order: ");
    for(a=0;a<n;a++)
    {
        if(a<n-1)
        {
            printf("%d, ",posi[a]);
        }
        else if(a==n-1)
        {
            printf(" %d ",posi[a]);
        }
    }
    return 0;
}