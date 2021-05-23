#ifndef SORTING_H
#define SORTING_H

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

//Sorting
void sorting(const char* file_name);

//Judge command
int judge_command(const char* command);

//Sort all students by command
int compare_function(const void* a1, const void* a2);


#endif
