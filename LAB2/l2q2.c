#include<stdio.h>
int main()
{
	int total,hundred,twenty,toonies,loonies;		//define intger variables
	printf("Enter a dollar amount:");			//print prompt user to enter
	scanf("%d",&total);					//user enters the amount of money as input

	hundred=total/100;					//calculate the number of hundred digits
	twenty=(total-hundred*100)/20;				//calculate the number of twenty 
	toonies=(total-hundred*100-twenty*20)/2;		//calculate the number of toonies
	loonies=(total-hundred*100-twenty*20-toonies*2);	//calculate the number of loonies
	//print output
	printf("$100 bulls: %d\n $20 bills: %d\n   Toonies: %d\n   Loonies: %d\n",hundred,twenty,toonies,loonies);

	return 0; 						//end program
}
