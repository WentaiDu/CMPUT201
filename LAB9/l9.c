#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


struct point
{
	float x;
	float y;
	struct point* next;
};

void printing(struct point* shape);
struct point* generate(int n);
struct point* index_sample(struct point* shape, int k);
struct point* get_point(struct point* shape, int k);
int get_points_count(struct point* shape);
float sample_distance(struct point* shape1, struct point* shape2, int k);
void release(struct point* shape);

FILE* file = NULL;

int main()
{
	file = fopen("example_run.txt", "a+");
	int shape1_n, shape2_n, sample_n;
	printf("Enter two integers in [1, 1000]:");
	scanf("%d%d", &shape1_n, &shape2_n);
	fprintf(file, "Enter two integers in[1, 1000]:%d %d\n", shape1_n, shape2_n);

	struct point* shape1 = generate(shape1_n);
	struct point* shape2 = generate(shape2_n);
	printf("Shape1 with %d points: ", shape1_n);
	fprintf(file, "Shape1 with %d points:", shape1_n);
	printing(shape1);
	printf("Shape2 with %d points: ", shape2_n);
	fprintf(file, "Shape2 with %d points:", shape2_n);
	printing(shape2);

	printf("Enter an integer in [2, 1000]:");
	scanf("%d", &sample_n);
	fprintf(file, "Enter an integer in [2, 1000]:%d\n", sample_n);

	float distance = sample_distance(shape1, shape2, sample_n);
	printf("The %d-sample distance is :%.3f\n", sample_n, distance);
	fprintf(file, "The %d-sample distance is :%.3f\n", sample_n, distance);

	release(shape1);
	release(shape2);
	fclose(file);
	return 0;
}


struct point* generate(int n)
{
	if (n <= 0)
	{
		return NULL;
	}

	srand((unsigned int)time(NULL));
	struct point* shape = (struct point*)malloc(sizeof(struct point));
	struct point* temp = shape;
	shape->x = rand() % 1000 + (rand() % 1001) * 0.001; //[0, 1000]
	shape->y = rand() % 1000 + (rand() % 1001) * 0.001;
	shape->next = NULL;

	for (int i = 1; i < n; i++)
	{
		temp->next = (struct point*)malloc(sizeof(struct point));
		temp->next->x = rand() % 1000 + (rand() % 1001) * 0.001;
		temp->next->y = rand() % 1000 + (rand() % 1001) * 0.001;
		temp->next->next = NULL;
		temp = temp->next;
	}
	return shape;
}

struct point* index_sample(struct point* shape, int k)
{
	int count = get_points_count(shape);
	int* point_index = (int*)malloc(sizeof(int) * k);

	for (int i = 0; i < k; i++)
	{
		int index = (i * count) / (k - 1);
		point_index[i] = index >= count ? count - 1 : index;
	}

	/*for (int i = 0; i < k; i++)
	{
		printf("%d\n", (int)point_index[i]);
	}*/

	struct point* sample = get_point(shape, point_index[0]);
	struct point* temp = sample;

	for (int i = 1; i < k; i++)
	{
		temp->next = get_point(shape, point_index[i]);
		temp = temp->next;
	}

	free(point_index);
	return sample;
}

struct point* get_point(struct point* shape, int k) 
{
	int i = 0;
	while (i != k)
	{
		shape = shape->next;
		i++;
	}
	struct point* point = (struct point*)malloc(sizeof(struct point));
	point->x = shape->x;
	point->y = shape->y;
	point->next = NULL;
	return point;
}

int get_points_count(struct point* shape)
{
	int count = 0;
	while (shape)
	{
		struct point* temp = shape->next;
		shape = temp;
		count++;
	}
	return count;
}

//
float sample_distance(struct point* shape1, struct point* shape2, int k)
{
	struct point* sample1 = index_sample(shape1, k);
	struct point* sample2 = index_sample(shape2, k);
	struct point* temp1=sample1;
	struct point* temp2=sample2;
	float distance = 0;

	printf("%d-sample of Shape1:", k);
	fprintf(file, "%d-sample of Shape1:", k);
	printing(sample1);
	printf("%d-sample of Shape2:", k);
	fprintf(file, "%d-sample of Shape2:", k);
	printing(sample2);

	while (temp1 && temp2)
	{
		distance += sqrt(pow((double)temp1->x - temp2->x, 2) + pow((double)temp1->y - temp2->y, 2));
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	release(sample1);
	release(sample2);
	return distance;
}

//Release memory
void release(struct point* shape)
{
	//Release linked list memory
	while (shape)
	{
		struct point* temp = shape->next;
		free(shape);
		shape = temp;
	}
}

//print and write in output
void printing(struct point* shape)
{
	if (!shape)
	{
		return;
	}

	printf("<");
	fprintf(file, "%s", "<");
	//Traverse
	while (shape->next)
	{
		printf("(%.3f,%.3f), ", shape->x, shape->y);
		fprintf(file, "(%.3f,%.3f), ", shape->x, shape->y);
		shape = shape->next;
	}
	printf("(%.3f,%.3f)>\n", shape->x, shape->y);
	fprintf(file, "(%.3f,%.3f)>\n", shape->x, shape->y);
}