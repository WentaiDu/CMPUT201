#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
    //define char variables
    char x[3][5];
    //define integer variables
    int a,b;
 
    //print prompt information
    printf("User to enter a string of 15 characters: ");
    //get user input
    for(a=0;a<3;a++)
    {
        for(b=0;b<5;b++)
        {     
            scanf("%c",&x[a][b]);
        }
    }

    //for-loops print the table in the 3 row by 5 column form. 
    printf("\n");
    for(a=0;a<3;a++)
    {
        for(b=0;b<5;b++)
        {
            printf("%c",x[a][b]);
        }
        printf("\n");
    }
    printf("\n");
    
    //check 3td line
    if(x[2][4]==x[2][0]&&x[2][0]==x[2][1]&&x[2][1]==x[2][2]&&x[2][2]==x[2][3]&&x[2][3]==x[2][4])
    {   
        //check 2nd line
        if(x[1][1]==x[1][2]&&x[1][2]==x[1][3]&&x[1][3]==x[2][2])
        {   
            //check 2nd line appears outside
            if(x[1][0]==x[1][1]||x[1][4]==x[1][1])
            {
                for(a=0;a<3;a++)
                {
                    for(b=0;b<5;b++)
                    {
                        printf("%c",x[a][b]);
                    }
                }
                printf("         This is not a pyramid: %c appears outside too\nYou have not entered a pyramid\n",x[2][2]);

            }

            //check 1st line
            else
            {
                //check 1st line
                if(x[0][2]==x[1][1])
                {
                    //check 1st line appears outside
                    if(x[0][0]==x[1][1]||x[0][1]==x[1][1]||x[0][3]==x[1][1]||x[0][4]==x[1][1])
                    {
                        //print is not a pyramid output
                        for(a=0;a<3;a++)
                        {
                            for(b=0;b<5;b++)
                            {
                                printf("%c",x[a][b]);
                            }
                        }
                        printf("         This is not a pyramid: %c appears outside too\nYou have not entered a pyramid\n",x[2][2]);
                    }

                    //This is a pyramid
                    else
                    {   //print is a pyramid output
                        for(a=0;a<3;a++)
                        {
                            for(b=0;b<5;b++)
                            {
                                printf("%c",x[a][b]);
                            }
                        }
                        printf("         This is a pyramid\nYou have entered a pyramid\n");
                    } 
                }
            }
        }

        //check 2nd line appears in a place
        else if(x[1][1]!=x[2][2])
        {
            //print is not a pyramid output
            for(a=0;a<3;a++)
            {
                for(b=0;b<5;b++)
                {
                    printf("%c",x[a][b]);
                }
            }
            printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[1][1],x[2][2]);
        }

        //check 2nd line appears in a place
        else if(x[1][2]==x[2][2])
        {
            //print is not a pyramid output
            for(a=0;a<3;a++)
            {
                for(b=0;b<5;b++)
                {
                    printf("%c",x[a][b]);
                }
            }
            printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[1][2],x[2][2]);
        }

        //check 2nd line appears in a place
        else if(x[1][3]==x[2][2])
        {
            //print is not a pyramid output
            for(a=0;a<3;a++)
            {
                for(b=0;b<5;b++)
                {
                    printf("%c",x[a][b]);
                }
            }
            printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[1][3],x[2][2]);
        }
    }

    //20-21
    else if(x[2][4]==x[2][0]&&x[2][1]!=x[2][2]&&x[2][2]==x[2][3]&&x[2][3]==x[2][4])
    {
        //print is not a pyramid output
        for(a=0;a<3;a++)
        {
            for(b=0;b<5;b++)
            {
                printf("%c",x[a][b]);
            }
        }
        printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[2][1],x[2][2]);
    }

    //21-22
    else if(x[2][4]==x[2][0]&&x[2][0]==x[2][1]&&x[2][2]!=x[2][3]&&x[2][3]==x[2][4])
    {
        //print is not a pyramid output
        for(a=0;a<3;a++)
        {
            for(b=0;b<5;b++)
            {
                printf("%c",x[a][b]);
            }
        }
        printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[2][2],x[2][3]);
    }

    //22-23
    else if(x[2][4]==x[2][0]&&x[2][0]==x[2][1]&&x[2][1]==x[2][2]&&x[2][3]!=x[2][4])
    {
        //print is not a pyramid output
        for(a=0;a<3;a++)
        {
            for(b=0;b<5;b++)
            {
                printf("%c",x[a][b]);
            }
        }
        printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[2][3],x[2][4]);
    }

    //23-24
    else if(x[2][4]!=x[2][0]&&x[2][0]==x[2][1]&&x[2][1]==x[2][2]&&x[2][2]==x[2][3])
    {
        //print is not a pyramid output
        for(a=0;a<3;a++)
        {
            for(b=0;b<5;b++)
            {
                printf("%c",x[a][b]);
            }
        }
        printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[2][4],x[2][0]);

    }

    //24-20
    else if(x[2][0]!=x[2][1]&&x[2][1]==x[2][2]&&x[2][2]==x[2][3]&&x[2][3]==x[2][4])
    {
        //print is not a pyramid output
        for(a=0;a<3;a++)
        {
            for(b=0;b<5;b++)
            {
                printf("%c",x[a][b]);
            }
        }
        printf("         This is not a pyramid: %c appears in a place of %c\nYou have not entered a pyramid\n",x[2][0],x[2][1]);    
    }
    return 0;
}