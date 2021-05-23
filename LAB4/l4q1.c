#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
    //define integer variables
    int a,b,c,d,e,low,high,mid;
    int temp;

    //print Prompt information
    printf("Enter the length of the array: ");
    //get input for length of integer c
    scanf("%d",&c);
    //define the arrat with length c
    int x[c];
    
    //print Prompt information
    printf("Enter %d integers to be sorted: ",c);
    //get the input intgers
    for(a=0;a<c;a++){
        scanf("%d",&x[a]);
    }

    //Bubble sort
    for(a=1;a<c;a++)
    {
       for(b=c-1;b>=a;b--)
        {
            //checking big or not
            if(x[b]<x[b-1])
            {
                temp=x[b-1];
                x[b-1]=x[b];
                x[b]=temp;
            }
        } 
    }
    //print output
    printf("In sorted non-decreasing order: ");
    //print non-decreasing order array
    for(d=0;d<c;d++){
        printf("%d ",x[d]);
    }

    //print Prompt information
    printf("\nEnter the integer you wish to locate: ");
    scanf("%d",&e);
    //define integer variables
    int position;
    int f=0,check=0;
    //check the integer user wish to locate in the array
    for(f=0;f<c;f++)
    {
        if(x[f]==e)
        {
            check=1;
            f=c+1;
        }
    }

    switch(check)
    {
        // case 0: when not in the array
        case 0:
            position=-1;
            break;

        // case 1: when in the array
        case 1:
            //binary search
            low=0;
            high=c-1;
            mid=(low+high)/2;
            while(low!=high)
            {
                //If the target is on the boundary
                if(x[high]==e)
                {
                    position=high+1;
                    low=high;
                }

                //If the target is on the boundary
                else if(x[low]==e)
                {
                    position=low+1;
                    low=high;
                }
                //binary search
                else
                {
                    //update mid
                    mid=(low+high)/2;

                    //check wether is or not target
                    if(x[mid]==e)
                    {
                        position=mid+1;
                        low=high;
                    }
                    //check right part
                    else if(x[mid]<e)
                    {
                        low=mid;
                    }

                    //check left part
                    else if(x[mid]>e)
                    {
                        high=mid;
                    }       
                }            
            }
            break;
    }
    //print output information
    printf("It's found at position/index: %d\n",position);
    return 0;
}