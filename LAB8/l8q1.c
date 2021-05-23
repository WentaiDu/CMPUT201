#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<time.h>
#include <string.h>
#define random(x) (rand()%x)


int mygetchar(){
    int c ;
    while((c=getchar())=='\n')
    {

    }
    return c;
}

int main()
{
    char *things;
    char*len[11];
    //memset(things, 0, sizeof(len));
    
    int i = 0;
    int l;
    char c;
    //declaration for time() function.
    time_t t;
    //Intializes random number generator
    srand((unsigned) time(&t));

    while(i<11)
    {
        things=malloc(101);
        if(fgets(things, 101, stdin) == NULL){break;}
        //printf("\n%s   %d true",things,i);
        if(strlen(things)<10||things[101]!='\0')
        {
            printf("\n invaild,the string of characters of length not in between 10 and 100.\n");
            return 0;
        }
        l=strlen(things)+1;
        //printf("%s",things);

        

        //printf("\n l is %d  when i is %d %s",l,i,things);
        len[i] = realloc(things,l);
        //strcpy(len[i],things);
        i++;
        //free(things);
    } 
    //printf("\n 11  is%s",len[10]);
    //printf("\nloop start\n");
    //for(int l=0;l<11;l++){printf("%s",len[l]);}
    //printf("\nloop end");
    //printf("\nerror1");
    //scanf("%c",&c);
    //printf("\nerror2");
    //c='\n';
    while((c=getchar())!=EOF)
    {   //printf("\nerror");

        if(c=='\r'||c=='\n')
        {

            int num=rand() % 11 +0;
            
            //printf("\n %d %s",num,len[num]);
            printf("\n%s",len[num]);
        }
    } 

    //for(int l=0;l<11;l++){free(len[i]);}
    
    return 0;
}

