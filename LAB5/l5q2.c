#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    //first number
    if(n==1)
    {
        return 0;
    }
    //second number
    else if(n==2)
    {
        return 1;
    }
    //third number
    else if(n==3)
    {
        return 2;
    }
    //after third number
    return fib(n-3) + fib(n-2) + fib(n-1);
}

int main()
{
    //define intger variables
    int a,b=0,result;
    while(b>=0)
    {
        //promote user to enter
        printf("Enter a position index: ");
        //get user input
        scanf("%d",&a);
        //check invalid
        if(a<=0)
        {
            //invalid input END
            break;
        }
        else
        {
            result=fib(a);
            printf("%d\n",result);
        }       
    }
    return 0;
}