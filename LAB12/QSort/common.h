#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "student.h"

//Read the file to get the count of line
int get_line_count(const char* file_name);

//Read the spreadsheet.txt to get the student information
struct student* read_file(const char* file_name, int* size);

//Release the memory
void release(struct student* student_list, int size);

//Print all students' information
void print_student_list(struct student* student_list, int size);

#endif
