#include "grading.h"

void grading()
{
	int a, b, c, d;
	FILE* file = fopen("grading_result.txt", "a+");
	FILE* output_file = fopen("graded_students.txt", "w");
	printf("enter four cutoffs for grade assignment: ");
	scanf("%d %d %d %d", &d, &c, &b, &a);
	fprintf(file, "enter four cutoffs for grade assignment: %d %d %d %d\n", d, c, b, a);
	
	if(!judge_cutoffs(a, b, c, d))
	{
		perror("Invalid cutoffs!\n");
		fprintf(file, "Invalid cutoffs!\n");
		return;
	}
	
	int size = 0;
	float average = 0;
	struct student* student_list = read_file("spreadsheet.txt", &size);
	
	fprintf(output_file, "Name Assignments Quizzes Labs FinalExam Total Grade\n");
	for(int i = 0; i < size; i++)
	{
		float total = student_list[i].total;
		if(total < d)
		{
			student_list[i].grade = 'F';
		}
		else if(total >= d && total < c)
		{
			student_list[i].grade = 'D';
			average += 1;
		}
		else if(total >= c && total < b)
		{
			student_list[i].grade = 'C';
			average += 2;
		}
		else if(total >= b && total < a)
		{
			student_list[i].grade = 'B';
			average += 3;
		}
		else
		{
			student_list[i].grade = 'A';
			average += 4;
		}
		fprintf(output_file, "%s %s %f %f %f %f %f %c\n", student_list[i].firstname, student_list[i].lastname, student_list[i].assignments, student_list[i].quizzes, student_list[i].labs, student_list[i].finalexam, student_list[i].total, student_list[i].grade);
	}
	average = average / size;
	printf("the class average grade is: %.2f\n", average);
	fprintf(file, "the class average grade is: %.2f\n", average);
	fclose(file);
	fclose(output_file);
	release(student_list, size);
}

int judge_cutoffs(int a, int b, int c, int d)
{
	return a > b && b > c && c > d;
}
