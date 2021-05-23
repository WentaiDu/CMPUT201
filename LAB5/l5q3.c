#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int matrix[80][80];
int initialization(int n);
int swap(int row1,int row2,int pos1,int pos2);
int balance1(int n);
int output(int n,int c);

int main()
{   
    //define intger variable
    int c,n;
    c=rand() %2+0;
    //print promte information
    printf("Enter the size of matrix, a positive even integer: ");

    //check input is even number and it is an integer between 2 and 80
    if((scanf("%d",&n)!=1)||n<2||n>80||n%2!=0)
    {
        return 0;
    }

    //print
    printf("Initial %dx%d matrix:",n,n);

    //Get the initialization matrix with a half 1 and a half 0
    initialization(n);
    //print matrix
    output(n,c);
    
    //balance the matrix
    balance1(n);

    //print output
    printf("\nFinal balanced matrix:");           
    printf("\n");
    output(n,c);
    return 0;
}

//Get the initialization matrix with a half 1 and a half 0
int initialization(int n)
{
    //declaration for time() function.
    time_t t;
    //Intializes random number generator
    srand((unsigned) time(&t));
    int a,b,c,x; 
    x=n/2;
    int random[n][x];

    for(a=0;a<n;a++)
    {   
        //choose a row by randomly
        random[a][0]=rand() %n+0;
        for(b=1;b<x;b++)
        {
            //get the random location for 1 in each 2 row
            random[a][b]=rand() %n+0;
            //remaining the random position     
            //check and delete duplicate positions
            for(c=0;c<b;c++)
            {
                if(random[a][b]==random[a][c])
                {
                    b--;
                }
            }
        } 
    }

    //Fill all the positions with 0
    for(a=0;a<n;a++)
    {       
        for(b=0;b<n;b++)
        {
            matrix[a][b]=0;
        }
    } 
    //refill the remaining positions with 1 
    for(a=0;a<n;a++)
    {       
        for(b=0;b<x;b++)
        {
            matrix[a][random[a][b]]=1;
        }
    }
    return 0;

}

//swap two position in the matrix
int swap(int row1,int row2,int pos1,int pos2)
{
    int x,y;
    x=matrix[row1][pos1];
    y=matrix[row2][pos2];
    matrix[row1][pos1]=y;
    matrix[row2][pos2]=x;   
    return 0; 
}

//balance the matrix
int balance1(int n)
{
    int a,b,c=0,d=0,m;

    int y[32000];
    int z[32000];

    for(a=0;a<n;a++)
    {
        //odd row
        if(a%2==0)
        {
            m=0;
        }
        //even row
        else if(a%2==1)
        {
            m=1;
        }

        //remaining positions
        for(b=m;b<n;b+=2)
        {
            //Check if it is 1 that should not be in this position and save the position
            if(matrix[a][b]!=1)
            {
                y[c]=a;
                y[c+1]=b;
                c+=2;
            }
            //Check if it is 0 that should not be in this position and save the position for odd row
            if(b%2==1&&matrix[a][b-1]!=0)
            {
                z[d]=a;
                z[d+1]=b-1;
                d+=2;
            }
            //Check if it is 0 that should not be in this position and save the position for even row
            else if(b%2==0&&matrix[a][b+1]!=0)
            {
                z[d]=a;
                z[d+1]=b+1;
                d+=2;
            }
        }
    }

    a=0;  
    //Exchange all positions that should be converted by the previously saved positions
    while(z[a]!=0||z[a+1]!=0||a==0)
    {
        //use swap function
        swap(y[a],z[a],y[a+1],z[a+1]);
        a+=2;
    }
    return 0;
}


//print matrix
int output(int n,int c)
{
    int a,b;
    if(c==0)
    {
        for(a=0;a<n;a++)
        {   
            printf("\n");    
            for(b=n-1;b>=0;b--)
            {
                printf("%d",matrix[a][b]);
            }
        } 
    }
    else if(c==1)
    {
        for(a=0;a<n;a++)
        {   
            printf("\n");    
            for(b=n-1;b>=0;b--)
            {
                printf("%d",matrix[a][b]);
            }
        } 
    }
    return 0;


}