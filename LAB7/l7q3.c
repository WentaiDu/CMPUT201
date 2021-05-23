#include <stdio.h>
#include <math.h>

int coefficient(int coeff,int remaining,int posi,int result[]);

int main()
{
    //int a0=1,a1=3,a2=9,a3=27,a4=81,a5=243,a6=729,a7=2187
    int input;
	int posi=0;
    int result[9]={0};
    printf("Enter a positive integer: ");
    scanf("%d",&input);
    if(input>1000||input<1)
    {
        return 0;
    }
    printf("coefficient sequence: ");
    coefficient(-1,input,posi,result);
    coefficient(0,input,posi,result);
    coefficient(1,input,posi,result);
    return 0;
}


// index determination 
int coefficient(int coeff,int remaining,int posi,int result[])
{
/*  
    int b0=1,b1=3,b2=9,b3=27,b4=81,b5=243,b6=729,b7=2187;
    int c[8]={2187,729,243,81,27,9,3,1}; */
    //Temporarily put in the undetermined coefficient
	result[posi] = coeff;
    //Calculate the remaining
	remaining = remaining-coeff*pow(3,posi++);

    //impossible to have a value >3^7
	if(posi>=8)
		return 0;
    //check length and print result
	if(remaining==0)
    {
		int a=8;
		//get length
		for(a=8;a>=0;a--)
        {
            if(result[a]!=0)
            {
                break;
            }
		}
        //print result
        int b=0;
        while(b<=a)
        {
            if(a==b)
            {
                printf("%d",result[b]);
            }
            else
            {
                printf("%d, ",result[b]);
            }
            b++;	
		}
		return 0;
	}
	//check whether coefficient is -1 or not 
	coefficient(-1,remaining,posi,result);
    //Reset
	result[posi]=0;
    //check whether coefficient is 0 or not 
	coefficient(0,remaining,posi,result);
    //Reset
	result[posi]=0;
    //check whether coefficient is 1 or not 
	coefficient(1,remaining,posi,result);
    //Reset
	result[posi]=0;
	return 0;
}
