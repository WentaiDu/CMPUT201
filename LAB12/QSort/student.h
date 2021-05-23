#ifndef STUDENT_H
#define STUDENT_H

struct student
{
	char* firstname;
	char* lastname;
	float assignments; //range [0, 21]
	float quizzes; //range[0, 14]
	float labs; //range[0, 30]
	float finalexam; //range[0, 30]
	float total; //range[0, 100]
	char grade; //range[F, D, C, B, A]
};

#endif 
