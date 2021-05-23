#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main()
{
    //define integer variables
	int player=1;
    int a_point=0,b_point=0,deduction,score,win_point=0;
    int number_die;
    int a,b,c,d;
    int e=0;
    int dies[10];
    int n_die[20000];

    //declaration for time() function.
    time_t t;

    //Intializes random number generator
    srand((unsigned) time(&t));

    //open an output file
    //FILE*fp=fopen("moves.txt","w");
    //for( d = 0 ; a < 11111 ; a++ )
    //{
    //    e=rand() % 4 + 1;
    //    fprintf(fp,"%d ",e);
    //



    //main loop to control the game end
	while(win_point<1000)
	{
        //Determine the player order
        player=player%2;
        for(d=0;d<20000;d++)
	    {
	    //get input
	    scanf("%d",&n_die[d]);
	    }

        switch(player)
		{
            //order for Alice
			case 1:
                //printf("Alice, entering the number (from 1 to 4) of six-sided die you would like to roll. %d",n_die[e]);
                number_die=n_die[e];
                //scanf("%d",&number_die);
                //fprintf(fp,"Alice, entering the number (from 1 to 4) of six-sided die you would like to roll. %d\n",number_die);
                break;

            //order for Bob
			case 0:
                //printf("Bob, entering the number (from 1 to 4) of six-sided die you would like to roll. %d",n_die[e]);
                number_die=n_die[e];
                //scanf("%d",&number_die);
                //fprintf(fp,"Bob, entering the number (from 1 to 4) of six-sided die you would like to roll. %d\n",number_die);
				break;
            //checking something wrong
            default:
                break;				
		}

        //define  an integer variable and assign values ​​to variable
        score=0;
        //print dies information
        //printf("\nYour dies: ");
        //wrinte the dies information in to the file
        //fprintf(fp,"Your dies: ");
        for( a = 0 ; a < number_die ; a++ ) 
        {   
            b=rand() % 6 + 1;
            dies[a]=b;
            //printf("%d ",dies[a]);
            //fprintf(fp,"%d ",dies[a]);
            score+=dies[a];
        }

        //Calculating deduction method
        switch(number_die)
        {
            //The player chooses 1 dice
            case 1:
                deduction=0;
                break;
            //The player chooses 2 dices
            case 2:
                deduction=-5;
                break;
            //The player chooses 3 dices
            case 3:
                deduction=-10;
                break;  
            //The player chooses 4 dices
            case 4:
                deduction=-20;
                break;
            ////The player chooses BIG OR EQUAL 5 dices
            default:
                //printf("Wrong number of die! Please restart the game!");
                //fprintf(fp,"Wrong number of die! Please restart the game!");
                break;
        }

        //Calculating deduction
        score+=deduction;
        //print the score each time	
        //printf("\nYour score at this time is : %d\n",score);
        //write the score each time in to the file
	    //fprintf(fp,"\nYour score at this time is : %d\n",score);

        //Calculating total poion and update the win_point
        switch(player)
        {
            case 1:
                a_point+=score;
                win_point=a_point;
                break;
            case 0:
                b_point+=score;
                win_point=b_point;
                break;
            default:
                break;
        }

        //checking the winer Alice
        if(a_point>=1000)
        {	
            //print Alice win output and point
            printf("\nAlice wins with %d points.\n",win_point);
            //write Alice win output and point in to the file
            //fprintf(fp,"\nAlice wins with %d points.\n",win_point);
            win_point=a_point;
        }

        //checking the winer Bob
        else if(b_point>=1000)
        {
            //print Bob win output and point
            printf("\nBob wins with %d points.\n",win_point);
            //write Bob win output and point in to the file
            //fprintf(fp,"\nBob wins with %d points.\n",win_point);
            win_point=b_point;
        }

        //no winer the game continue
        //else
        //{
            //print total score for the current player
            //printf("Your total score is : %d\n\n",win_point);
            //write total score for the current player in to the file
            //fprintf(fp,"Your total score is : %d\n\n",win_point);
        //}
        //update the player order
        player+=1;
    }
    //close the file
    //fclose(fp);
    return 0;
}