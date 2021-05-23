#include<stdio.h>
int main()
{
	int amount;									//define integer variable

	printf("How many windows do you have: ");					//print promote information
	scanf("%d",&amount);								//user enter amount as input

	float money;									//define float variable
	
	//if condition for check invalid quanrity
	if(amount<0)
	{
		printf("Please enter a valid quanrity\n");				//print valid request
	}

	//else if condition for check amount is 0
	else if(amount==0)
	{
		money=0;								//assign 0 to money
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print money spent
	}

	//else if condition for check amount <=24 
	else if(amount<=24)
	{	
		money=amount*8+25;							//calculate the cost
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print cost
	}

	//else if condition foe check amount <=49
	else if(amount<=49)
	{	
		money=amount*8*0.95+25;							//calculate the cost 
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print cost
	}

	//else if condition for check amount<=99
	else if(amount<=99)
	{	
		money=amount*8*0.9+25;							//calculate the cost
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print cost
	}

	//else if condition for check amount <=499
	else if(amount<=499)	
	{	
		money=amount*8*0.8+25;							//calculate the cost
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print cost
	}

	//else condition for check amount>499
	else
	{
		money=amount*8*0.6+25;							//calculate the cost
		printf("Your estimate for window cleaning is: $%.1f\n",money);		//print cost
	}
	return 0;									//end program
}
