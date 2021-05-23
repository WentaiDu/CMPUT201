#include<stdio.h>
#include<stdlib.h>

float calculate_addition(float num_one, float num_two) {
    return num_one + num_two;
} 

int main()
{
    
    //set up two float variables and interface to accept from user input
    //print the sum of the entered two float numbers
    float num_one,num_two;
    printf("user enter: ");
    scanf("%f%f",&num_one,&num_two);


    printf("%.2f\n", calculate_addition(num_one, num_two));
    return 0;
}
 
