#include <stdio.h>
void byte_value(int *);
int main() {
    int n = 1;
    //int n;
    byte_value(&n);
    
    printf("Enter an integer: ");
    if (scanf("%d", &n) == 1)
        byte_value(&n);
    

/* 
    unsigned u = 0xdeadbeef;
    unsigned char *p = (unsigned char *)&u;

    prn_all (p, sizeof u); */


    return 0;        
}
void byte_value11(const unsigned int *p) {
    // fill in the body using only pointer variables
    // printout the memory address of the byte and its unsigned char (integer) value
    // one line for each pair, a total of 4 lines
    printf("%d", *p);
    return;
    }

void byte_value (int *p)
{
    unsigned char *c = (unsigned char *)p;

    for(int i=0;i<4;i++)
    {
        //printf("%p  %x\n",p+i,*(p+i)); 
        //printf("%p  %d\n",c+i,(unsigned char)*(c+i)); 
        printf("%p  %d\n",c,*c); 
        c++;

        
       // printf("%p %x\n",*(unsigned char*)(c+i));
    }
    return;
}


void byte_value23 (int *p)
{
    //char *c=(char*)&p;
    unsigned char* c = (unsigned char*)p;

    for(int i=0;i<4;i++)
    {
        //printf("%p  %x\n",p+i,*(p+i)); 
        //printf("%p  %d\n",c+i,(unsigned char)*(c+i)); 
        printf("%p  %d\n",c+i,*(p+i)); 

        
       // printf("%p %x\n",*(unsigned char*)(c+i));
    }
    return;
}
