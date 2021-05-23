OPT = -Wall -std=c99

sorting: sorting_main.o sorting.o common.o
	gcc $(OPT) -o sorting main.o sorting.o common.o
	
sorting_main.o: main.c sorting.h
	gcc $(OPT) -D SORTING -c main.c 
	
sorting.o: sorting.c sorting.h student.h common.h
	gcc $(OPT) -c sorting.c
	
common.o: common.c common.h student.h
	gcc $(OPT) -c common.c
	
grading: grading_main.o grading.o common.o
	gcc $(OPT) -o grading main.o grading.o common.o

grading_main.o: main.c grading.h
	gcc $(OPT) -c main.c
	
grading.o: grading.c common.h
	gcc $(OPT) -c grading.c
	
clean:
	rm -f *.o sorting grading grading_result.txt graded_students.txt
	
