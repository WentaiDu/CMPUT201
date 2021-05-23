#include <stdio.h>
#define N 10

int main()
{
    int b[N];
    int*a =&b[0];
    int *p = a, *q = a + N - 1;
    for (int i = N-1; i >= 0 ; i--) {
        *(a + i) = i + 1;
    }
    while (p < q) {
        int temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
        
/*      for (int i = 0; i < N; i++) 
    {
        printf("%d ", b[i]);
    }  */

/*      for(*a;*a;*a++)
    {
        printf("%d ", *a);
    } */ 

    for (int* b =a+N ; a<b ;a++)
    {
        //printf("\na is%d \n b is %d ", *a,*b);
        printf("%d ", *a);
    }


    printf("\n");
  
    return 0;

}

