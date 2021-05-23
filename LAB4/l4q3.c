#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    //set char array for choose the game mode
    char mode[1];
    //set int variable for contral game continue
    int game=0;
    //print prompt information
    printf("Integer conversion in decimal (d), octal (o), or hexadecimal (h)? ");
    //get user input
    fgets(mode,10,stdin);

    //Control the game end or continue
    while(game>=0)
    {
        //set char array 
        char a[20000];
        //set array as 0 each time
        memset(a,0,20000);
        //print prompt information
        printf("Enter a message: ");
        //get user input
        fgets(a,20000,stdin);

        //checking game end
        if(a[0]=='E'||a[0]=='e')
        {
            if(a[1]=='X'||a[1]=='x')
            {
                if(a[2]=='I'||a[2]=='i')
                {
                    if(a[3]=='T'||a[3]=='t')
                    {
                        //game end
                        game=-1;
                        break;
                    }

                    else
                    {







                        
                    }
                }
            }
        } 

        //game continue
          
        //decimal (d)
        if(mode[0]=='d')
        {
            int b=0;
            while(b>=0)
            {   
                //print end
                if(a[b]==10)
                {
                    b=-3;
                }

                //print output
                else
                {
                    printf("%d ",a[b]);
                    b++;
                }
            }
            printf("\n");
        }

        //octal (o)
        else if(mode[0]=='o')
        {
            //set int variables
            int b=0,c=0,z=1,d;
            //set int array
            int m[20000];
            int n[20000];

            while(c>=0)
            {   
                if(a[c]!=10)
                {   
                    //copy the input and change char to int
                    m[c]=a[c];
                    b=0;
                    z=1;

                    //transfer int from decimal to octal
                    while(m[c]!=0)
                    {      
                        d=(m[c]%8)*z;
                        b+=d;
                        m[c]=m[c]/8;
                        z=z*10;
                        //update into n array
                        n[c]=b;          
                    }
                    //print output
                    printf("%d ",n[c]);
                    c++;              
                }

                //print end
                else
                {
                    c=-2;
                }
            }
            printf("\n");
        }

        //hexadecimal (h)
        else if(mode[0]=='h')
        {
            //set int variables
            int b=0,e,g;
            //set int array
            int m[20000];
            //set hexadecimal form array
            char n[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

            while(b>=0)
            {
                //print end
                if(a[b]==10)
                {
                    b=-55;                            
                }

                //print output
                else
                {
                    m[b]=a[b];
                    e=m[b]%16;
                    g=m[b]/16;
                    printf("%c%c ",n[g],n[e]); 
                    b++;                        
                } 
            } 
            printf("\n");
        } 

        //Invalid choice
        else
        {
            printf("Invalid choice, game over");
            game=-1;
        }
            
    } 
    return 0;
}