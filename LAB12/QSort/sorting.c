#include "sorting.h"

//The commands of "sort all students by: XXX"
char* commands[7] = {"Name", "Assignments", "Quizzes", "Labs", "FinalExam", "Total", "Grade"};

//Sort command
char command[20];

void sorting(const char* file_name)
{
	printf("sort all student by: ");
	scanf("%s", command);
	if(!judge_command(command))
	{
		perror("Invalid command!\n");
		return ;
 	}
 	
 	int size = 0;
	struct student* student_list = read_file(file_name, &size);
	qsort(student_list, size, sizeof(struct student), compare_function);
	print_student_list(student_list, size);
	release(student_list, size);
}


int judge_command(const char* command)
{
	for(int i = 0; i < 7; i++)
	{
		if(strcmp(commands[i], command) == 0)
		{
			return 1;
		}
	}
	return 0;
}


int compare_function(const void* a1, const void* a2)
{
	struct student* b1 = (struct student*)a1;
	struct student* b2 = (struct student*)a2;
	
	if(strcmp(command, commands[0]) == 0) // Name
	{
		return strcmp(b1->firstname, b2->firstname) > 0; 
	}
	else if(strcmp(command, commands[1]) == 0) // Assignments
	{
		return b1->assignments >= b2->assignments;
	}
	else if(strcmp(command, commands[2]) == 0) // Quizzes
	{
		return b1->quizzes >= b2->quizzes;
	}
	else if(strcmp(command, commands[3]) == 0) // Labs
	{
		return b1->labs >= b2->labs;
	}
	else if(strcmp(command, commands[4]) == 0) // FinalExam
	{
		return b1->finalexam >= b2->finalexam;
	}
	else if(strcmp(command, commands[5]) == 0) // Total
	{
		return b1->total >= b2->total;
	}
	else //Grade
	{
		return b1->grade <= b2->grade;
	}	
}


