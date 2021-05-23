#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

FILE* file = NULL;
const char* operation[7] = {"add", "sub", "mul", "div", "mod", "pow", "log"};

//Determine whether it is a number and valid
int is_digital(int index, char character)
{
	return (character >= '0' && character <= '9') || character == '.' || (character == '-' && index == 0);
}

//Check whether the parameter argc  that passed by the main function is 4
int judge(int argc, char** argv)
{
	int operation_index = -1;
	if(argc == 4)
	{
		for(int i = 0; i < 7; i++)
		{
			//Check whether it is reasonable arithmetic (Whether the option entered by the user is in the array) and return the operation index
			if(strcmp(operation[i], argv[1]) == 0)
			{
				operation_index = i;
				break;
			}
		}
		for(int i = 0; argv[2][i]; i++)
		{
			if(!is_digital(i, argv[2][i]))
			{
				return -1;
			}
		}
		for(int i = 0; argv[3][i]; i++)
		{
			if(!is_digital(i, argv[3][i]))
			{
				return -1;
			}
		}
		return operation_index; 
	}
	return -1;
}

void arithmetic(int operation_index, const char* str1, const char* str2)
{
	char message[256];
	if(strchr(str1, '.') == 0 && strchr(str2, '.') == 0) //both are integer
	{
		int num1 = atoi(str1);
		int num2 = atoi(str2);
		int result = 0;
		float log_result = 0;
		switch(operation_index)
		{
			case 0:
				result = num1 + num2;
				sprintf(message, "addition for %s, %s is %d\n", str1, str2, result);
				break;
			case 1:
				result = num1 - num2;
				sprintf(message, "subtraction for %s, %s is %d\n", str1, str2, result);
				break;
			case 2:
				result = num1 * num2;
				sprintf(message, "multiplication for %s, %s is %d\n", str1, str2, result);
				break;
			case 3:
				if(num2 == 0)
				{
					sprintf(message, "division cannot be performed for %s, %s\n", str1, str2);
				}
				else
				{
					result = num1 / num2;
					sprintf(message, "division for %s, %s is %d\n", str1, str2, result);
				}
				break;
			case 4:
				result = num1 % num2;
				sprintf(message, "modulo for %s, %s is %d\n", str1, str2, result);
				break;
			case 5:
				result = (int)pow(num1, num2);
				sprintf(message, "power for %s, %s is %d\n", str1, str2, result);
				break;
			case 6:
				log_result = log(num2) / log(num1);
				sprintf(message, "logarithm for %s, %s is %f\n", str1, str2, log_result);
				break;
		}
	}
	else
	{
		//transfer str to double
		float num1 = atof(str1);
		float num2 = atof(str2);
		float result = 0;
		switch(operation_index)
		{
			case 0:
				result = num1 + num2;
				sprintf(message, "addition for %s, %s is %f\n", str1, str2, result);
				break;
			case 1:
				result = num1 - num2;
				sprintf(message, "subtraction for %s, %s is %f\n", str1, str2, result);
				break;
			case 2:
				result = num1 * num2;
				sprintf(message, "multiplication for %s, %s is %f\n", str1, str2, result);
				break;
			case 3:
				if(num2 == 0)
				{
					sprintf(message, "division cannot be performed for %s, %s\n", str1, str2);
				}
				else
				{
					result = num1 / num2;
					sprintf(message, "division for %s, %s is %f\n", str1, str2, result);
				}
				break;
			case 4:
				sprintf(message, "modulo cannot be performed for %s, %s\n", str1, str2);
				break;
			case 5:
				result = (float)pow(num1, num2);
				sprintf(message, "power for %s, %s is %f\n", str1, str2, result);
				break;
			case 6:
				result = log(num2) / log(num1);
				sprintf(message, "logarithm for %s, %s is %f\n", str1, str2, result);
				break;
		}
	}
	printf("%s", message);
	fprintf(file, "%s", message);
}

int main(int argc, char** argv)
{
	file = fopen("example_run.txt", "a+");
	fprintf(file, "./operation %s %s %s\n",argv[1],argv[2],argv[3]);
	int result = judge(argc, argv);
	if(result == -1)
	{
		printf("%s%s%s\n", "Usage: ", argv[0], " [add|sub|mul|div|mod|pow|log Num Num]");
		fprintf(file, "%s%s%s\n", "Usage: ", argv[0], " [add|sub|mul|div|mod|pow|log Num Num]");
		return 0;
	}
	arithmetic(result, argv[2], argv[3]);
	fclose(file);
	return 0;
}



