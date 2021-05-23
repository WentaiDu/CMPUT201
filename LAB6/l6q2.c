#include <stdio.h>
#include <stdlib.h>
int n,u=0,w=0,num_comps=0,num_moves=0;

void enterNumber(int *d)
{
    int t,c;
    //promote information
    printf("Enter 11 integers to be sorted: ");
    //get integer input
    for (t=0;t<n; t++) 
    {
        scanf("%d",&c);
        *(d + t)=c;
    }
}

void bubblesort(int *a)
{
    int temp;
    int x,y;
    int *b=a;
    for(x=0;x<n-1;x++)       
    {
        a=b;
        for(y=0;y<n-x-1;y++)
        {
            //check big or not
            if(*a>*(a+1))
            {
                //exchange
                temp=*a;
                *a=*(a+1);
                *(a+1)=temp;
                num_moves+=2;
            }
            //updata the num_comps and num_moves
            a++;
            num_comps++;
        }
    }
}

void insertionsort(int *a)
{
    int temp,x,y;
    for(x=0;x<n;x++)
    {
        for(y=0;y<x;y++)
        {
            if(*(a+y)>*(a+x))
            {
                temp=*(a+x);
                *(a+x)=*(a+y);
                *(a+y)=temp;
                //updata the num_moves
                num_moves+=2;
            }
            //updata the num_comps
            num_comps++;
        }
    }
}

void merge(int y1[], int low, int mid, int hight)
{
    //Allocate memory and define
	int* temp = (int*)malloc((hight-low+1)*sizeof(int));
	int left1 = low;
	int right1 = mid;
	int left2 = mid+1;
	int right2 = hight;
    int g,h;
    //merge
    g=0;
	while (left1<=right1 && left2<=right2)
	{
        //Compare two value, put smaller one to merge,
		if (y1[left1]<y1[left2])
        {
			temp[g] = y1[left1++];
            //updata the num_comps and num_moves
            num_moves+=2;
            num_comps++;
        }
        //updata the posi
		else{
			temp[g] = y1[left2++];
            //updata the num_comps
            num_comps++;
        }
        g++;
	}
    //Check the remaining elements 1
    if(left1<=right1)
    {
        h=left1;
        while(h<=right1)
        {
            temp[g++]=y1[h];
            num_comps++;
            h++;
        }
    }
    //Check the remaining elements 2
    if(left2<=right2)
    {
        h=left2;
        while(h<=right2)
        {
            temp[g++]=y1[h];
            num_comps++;
            h++;
        }
    }
    //update the initial
    int i=0;
    while(i<hight-low+1)
    {
        y1[low+i] = temp[i];
        i++;
    }
    //Release memory
    free(temp);
}

void mergesort(int y1[],int low,int hight)
{
	int mid;
    mid=(low+hight)/2;
	if (low <hight)
	{
        mergesort(y1,low,mid);
        mergesort(y1,mid+1,hight);
        merge(y1,low,mid,hight);
	}
}

void quicksort(int left,int right,int z[])
{
    int temp,x,y,mid;
    x=left;
    y=right;
    mid = z[(x+y)/2];
    while(x<=y)
    {
        //check left part
        while((z[x]<mid)&&(x<right))
        {
            x++;
            //updata the num_comps
            w++;
        }
        //check right part
        while((z[y]>mid)&&(y>left))
        {
            y--;
            //updata the num_comps
            w++;
        }
        if(x<=y)
        {
            temp=z[x];
            z[x]=z[y];
            z[y]=temp;
            x++;
            y--;
            //updata the num_moves
            u+=2;
        }
        //updata the num_comps
        w++;
    }
    //left part
    if(left<y)
    {
        quicksort(left,y,z);
    }
    //right part
    if(right>x)
    {
        quicksort(x,right,z);
    }
}

void print_array(int *a)
{
    int i;
    printf("\nIn sorted non-decreasing order:");
    for(i=0;i<n;i++)
    {
        printf("%d ",*a);
        a++;
    }
    printf("\nNumber of comparisons: %d",num_comps);
    printf("\nNumber of moves: %d\n",num_moves);
    num_comps=0,num_moves=0;

}
char mode()
{
    printf("Select from (a)ll | (b)ubblesort | (i)nsertionsort | (m)ergesort | (q)uicksort: ");
    char c;
    scanf("%c",&c);
    scanf("%c",&c);
    return c;
}


int main()
{
    int i;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int initial[n];
    enterNumber(initial);
    int *a = initial;
    char algorithm=mode();
    int new[n],new2[n],new3[n],new4[n];
    for(i=0;i<n;i++)
        {
            new[i]=initial[i];  
            new2[i]=initial[i];  
            new3[i]=initial[i]; 
            new4[i]=initial[i];    
        }
    int *bubble=new;
    int *inser=new2;
    int *me=new3;
    int *quick=new4;
    if(algorithm=='a')
    {
        printf("Allsort is deployed ...");
        printf("\nBubblesort is deployed ...");
        bubblesort(bubble);
        print_array(bubble);

        printf("\nInsertionsort is deployed ...");
        insertionsort(inser);
        print_array(inser);

        printf("\nMergesort is deployed ...");
        mergesort(me,0,n-1);
        print_array(me);

        printf("\nQuicksort is deployed ...");
        quicksort(0,n-1,new4);
        num_comps=w;
        num_moves=u;
        print_array(new4);
    }
    else if(algorithm=='b')
    {
        printf("Bubblesort is deployed ...");
        bubblesort(a);
        print_array(a);
    }
    else if(algorithm=='i')
    {
        printf("Insertionsort is deployed ...");
        insertionsort(inser);
        print_array(inser);
    }
    else if(algorithm=='m')
    {
        printf("Mergesort is deployed ...");
        mergesort(me,0,n-1);
        print_array(me);
    }
    else if(algorithm=='q')
    {
        printf("Quicksort is deployed ...");   
        quicksort(0,n-1,quick);
        num_comps=w;
        num_moves=u;
        print_array(quick);
    }
    return 0;


}