#include<stdio.h>
int main()
{
	//define integer variables
	int x;
	int y;
	int z;
	//Assign values ​​to variables
	x=99;
	z=99;
	//while loop
	while(x>=1)
	{
		switch(x)
		{	
			// case 1: when only 1 bottles left
			case 1:
				printf("%d bottles of beer on the wall,\n%d bottles of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",x,x,x-1);
				x--;
				break;	
			// other case: when the bottles > 1
			default:
		
				

				printf("%d bottles of beer on the wall,\n%d bottles of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",x,x,x-1);
				x--;
	
				break;
				
		}

	}

	//for loop
	for(y=99;y>0;y--)
	{
		switch(y)
		{	
			// case 1: when only 1 bottles left
			case 1:
				printf("%d bottles of beer on the wall,\n%d bottles of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",y,y,y-1);
			
				break;
			// other case: when the bottles > 1
			default:
				printf("%d bottles of beer on the wall,\n%d bottles of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",y,y,y-1);
			
				break;	
		}
	}

	//do while loop	
	do
	{	
		switch(z)
		{	
			// case 1: when only 1 bottles left
			case 1:	
				printf("%d bottle of beer on the wall,\n%d bottle of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",z,z,z-1);
				break;
			// other case: when the bottles > 1
			default:
				printf("%d bottles of beer on the wall,\n%d bottles of beer.\nTake one down, pass it around,\n%d Bottles of beer one the wall.\n\n",z,z,z-1);
				break;
		}
		z--;
	}
	while(z>=1);

	return 0;
}

