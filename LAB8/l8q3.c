#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<time.h>
#include <string.h>
typedef unsigned char           uint8_t;
void byte_value(int *);
int main(){
    float a;
/* 
    unsigned u = 0xdeadbeef;
    unsigned char *p = (unsigned char *)&u;

    prn_all (p, sizeof u); */

    printf("Enter a floating-point number: ");
    scanf("%f", &a);
    uint8_t * a1 =(  uint8_t *)&a;   
    uint8_t * a3 =a1+2;

     
/*  printf("%d  %d %d %d\n",*a1,uint8_t * a2 =a1+1,*a3,uint8_t * a4 =a1+3); */
    int b = 0;
    if(*a3>=128)
    {
        *a3-=128;
        b = 1;
    }
    else
    {
        *a3+=128;
    }
    if(b==1){
        uint8_t * a4 =a1+3;
        *a4+=1;
    }

    printf("Doubling becomes %f\n",a);
}

void byte_value (int *p)
{
    unsigned char *c = (unsigned char *)p;

    for(int i=0;i<8;i++)
    {
        //printf("%p  %x\n",p+i,*(p+i)); 
        //printf("%p  %d\n",c+i,(unsigned char)*(c+i)); 
        printf("%p  %d\n",c,*c); 
        c++;

        
       // printf("%p %x\n",*(unsigned char*)(c+i));
    }
    return;
}