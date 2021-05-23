#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10000];
    int i1, j1,i2,j2,a,b;
    int l = 0;
    printf("Enter two positive integers: ");
    scanf("%d%d", &i1, &j1); // need to validate both being positive
    i2 = i1,j2 = j1;
    while (i2 != j2) {
        if(i2>j2){
            arr[l]=0;
        }else{
            arr[l]=1;
        }
        l++;
        i2 > j2 ? (i2 -= j2) : (j2 -= i2);
    }
    int gcd = i2;
    a = 0;
    b = 1;

    for(int k = l-1;k>=0;k--){
        if(arr[k]==0){
            b = b-a;
        }else{
            a = a - b;
        }
    }
    if(a>=0&&b>=0)
    {
        printf("GCD: %d = %d * %d + %d * %d\n", gcd,a,i1,b,j1);
    }
    else if(a<0&&b>0)
    {
        printf("GCD: %d = (%d) * %d + %d * %d\n", gcd,a,i1,b,j1);
    }
    else if(a>0&&b<0)
    {
        printf("GCD: %d = %d * %d + (%d) * %d\n", gcd,a,i1,b,j1);
    }
    else if(a<0&&b<0)
    {
        printf("GCD: %d = (%d) * %d + (%d) * %d\n", gcd,a,i1,b,j1);
    }
    return 0;
}
