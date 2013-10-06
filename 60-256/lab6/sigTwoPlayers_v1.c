#include <unistd.h>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//my signal handler
void action(int signo){
    printf("Received SIGUSR1 signal!\n");
}

int roll_dice(){
    return rand() % 10 + 1;
}

void play_game(char *, int);

int main()
{
    pid_t pid1, pid2;

    printf("\nThis is a 2-players game with a referee\n");

  //create two palyers
    if((pid1 = fork()) == 0) play_game("Player 1", 1);
    if((pid2 = fork()) == 0) play_game("Player 2", 2);

    /**************
     Notice, due the design of function play_game(), the following
     statements will be executed only by the parent (referee)
    ***************/

  //referee waits for a sec
    sleep(1);

  //continue until the end of the game, when the
  //signal SIGTERM is received from one of the players
    while(1)
    {
        printf("Referee: Player 1 plays\n\n");

      //send signal SIGUSR1 to player 1
        kill(pid1, SIGUSR1);

      //wait for the signal SIGUSR1 back (from player 1)
        signal(SIGUSR1, action);
        pause();

      //after getting back the signal SIGUSR1
        printf("Referee: Player 2 plays\n\n");

      //send signal SIGUSR1 to player 2
        kill(pid2, SIGUSR1);

      //wait for the signal SIGUSR1 back (from player 2)
        signal(SIGUSR1, action);
        pause();

      //after getting back the signal SIGUSR1
      //go back to the beginning of the while loop
    }
}

void play_game(char *name, int player_number)
{
    int points = 0;
    int dice;

  //Make sure to create different
  //random sequences for each player.
    srand(time(NULL) + player_number);

   //Both players will continue until the end of the game, when
   //the winning player will generate and send the SIGTERM signal
   //to terminate all the processes in the group, including itself.
    while(1)
    {
      //wait for the signal SIGUSR1 from referee
        signal(SIGUSR1, action);
        pause();

      //after getting the signal SIGUSR1 from referee
        printf("%s: playing my dice\n", name);

      //rool the dice
        dice = roll_dice();

        printf("%s: got %d points\n", name, dice);
      //add points to hand
        points += dice;

        printf("%s: Total so far %d\n\n", name, points);

        sleep(2);

        if(points >= 40)
        {
            printf("%s: Game over, I won!\n", name);

          //Send the terminating signal SIGTERM to all the processes
          //(players and the referee) in the group, including itself.
            kill(0, SIGTERM);
        }

      //otherwise, send signal SIGUSR1 to the referee (parent)
        kill(getppid(), SIGUSR1);
    }
}
     
