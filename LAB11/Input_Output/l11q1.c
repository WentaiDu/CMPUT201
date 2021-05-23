#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <memory.h>

char file_content[1000][100];
char number_list[1000][50];
unsigned int line_count = 0;
unsigned int n = 0;

void generate_number_list()
{
	unsigned int k = 0;
	unsigned int temp_n = n;
	while (temp_n)
	{
		k++;
		temp_n /= 10;
	}
	for(unsigned int i = 1; i <= n; i++)
	{
		unsigned int temp_i = i;
		unsigned int digits = 0;
		char str_i[20];
		while(temp_i)
		{
			digits++;
			temp_i /= 10;
		}
		for(unsigned int j = 0; j < k - digits; j++)
		{
			strcat(number_list[i - 1], "0");
		}
		sprintf(str_i, "%d", i); //convert int to string
		strcat(number_list[i - 1], str_i);
		//printf("%s\n", number_list[i - 1]);
	}
}

void get_file_content(const char* file_name)
{
	FILE* file = NULL;
	file = fopen(file_name, "r");
	while (fgets(file_content[line_count++], 100, file) != NULL);
	fclose(file);
}

void write_files()
{
	for(unsigned int i = 0; i < n; i++)
	{
		char file_name[100];
		char beginning[100];
		//clear the content of array
		memset(file_name, 0, sizeof(file_name));
		memset(beginning, 0, sizeof(beginning));
		
		strcat(beginning, "Content of output");
		strcat(file_name, "output");
		strcat(file_name, number_list[i]);
		strcat(file_name, ".txt");
		strcat(beginning, number_list[i]);
		strcat(beginning, ".txt:");
		
		FILE* file = fopen(file_name, "w");
		fprintf(file, "%s\n", beginning);
		for(unsigned int j = 0; j < line_count; j++)
		{
			fprintf(file, "%s", file_content[j]);
		}
		fclose(file);
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Usage: ./%s input.txt\n", argv[0]);
		return 0;
	}
	printf("Enter the number of output files: ");
	scanf("%d", &n);

	get_file_content(argv[1]);
	generate_number_list();
	write_files();

	return 0;
}
