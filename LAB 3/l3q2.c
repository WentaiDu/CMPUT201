#include<stdio.h>
int main()
{
	//define integer variables
	int a[20];
	int x;
	int z;
	int temp;

	//open the file from local
	//FILE*fp = fopen("array.txt","r");
	//for(x=0;x<20;x++)
	//{
	//fscanf(fp,"%d",&a[x]);
	//}
	//fclose(fp);

	//print Prompt information
	printf("Enter 20 integers: ");
	for(x=0;x<20;x++)
	{
	//get input
	scanf("%d",&a[x]);
	printf("%d ",a[x]);
	}

//print all elements in a[]
//	int y;
//	for(y=0;y<20;y++)
//	{
//		printf("%d ",a[y]);
		//printf("\n");
//	}
//	printf("\n");

	//Bubble sort
	for(z=1;z<20;z++)
	{
		int m;
		for(m=19;m>=z;m--)
		{
			//checking big or not
			if(a[m]<a[m-1])
			{	
				temp=a[m-1];
				a[m-1]=a[m];
				a[m]=temp;
			}
		}
	} 

//	int n;
//	for(n=0;n<20;n++)
//	{
//		printf("%d ",a[n]);
//	}

	//print output
	printf("\nLargest: %d\nSecond largest: %d\n",a[19],a[18]);
	//open output file
	FILE*fp2=fopen("20_output.txt","w");
	//write output in to dile
	fprintf(fp2,"Enter 20 integers: ");
	int loop;
	for(loop=0;loop<20;loop++)
	{	
		fprintf(fp2,"%d ",a[loop]);
	}
	fprintf(fp2,"\nLargest: %d\nSecond largest: %d\n",a[19],a[18]);	
	//close the output file
	fclose(fp2);
	return 0;
}
