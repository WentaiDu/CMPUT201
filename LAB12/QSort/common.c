#include "common.h"

int get_line_count(const char* file_name)
{
	FILE* file = fopen(file_name, "r");
	char line[200];
	int count = 0;
	while(fgets(line, sizeof(line), file))
	{
		count++;
	}
	fclose(file);
	return count;
}

struct student* read_file(const char* file_name, int* size)
{
	*size = get_line_count(file_name) - 1;
	struct student* student_list = (struct student*)malloc(sizeof(struct student) * (*size));
	FILE* file = fopen(file_name, "r");
	int line_count = 0;
	int is_spreadsheet = strcmp(file_name, "spreadsheet.txt") == 0;
	char line[200];
	
	while(!feof(file) && line_count < (*size) + 1)
	{
		if(line_count == 0) //ignore first line
		{
			fgets(line, sizeof(line), file);
			line_count++;
		}
		struct student* temp = &student_list[line_count - 1];
		temp->firstname = (char*)malloc(sizeof(char) * 100);
		temp->lastname = (char*)malloc(sizeof(char) * 100);
		if(is_spreadsheet)
		{
			fscanf(file, "%s %s %f %f %f %f", temp->firstname, temp->lastname, &temp->assignments, &temp->quizzes, &temp->labs, &temp->finalexam);
			temp->total = temp->assignments + temp->quizzes + temp->labs + temp->finalexam;
			temp->grade = '-';
		}
		else
		{	
			fscanf(file, "%s %s %f %f %f %f %f %c", temp->firstname, temp->lastname, &temp->assignments, &temp->quizzes, &temp->labs, &temp->finalexam, &temp->total, &temp->grade);	
		}
		line_count++;
	}
	fclose(file);
	return student_list;
}


void release(struct student* student_list, int size)
{
	for(int i = 0; i < size; i++)
	{
		free(student_list[i].firstname);
		free(student_list[i].lastname);
	}
	free(student_list);
}

void print_student_list(struct student* student_list, int size)
{
	printf("Name Assignments Quizzes Labs FinalExam Total Grade\n");
	for(int i = 0; i < size; i++)
	{
		struct student* temp = &student_list[i];
		printf("%s %s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c\n", temp->firstname, temp->lastname, temp->assignments, temp->quizzes, temp->labs, temp->finalexam, temp->total, temp->grade);
	}
}


