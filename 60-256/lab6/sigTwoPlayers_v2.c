#include <unistd.h>
#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//This signal handler can handle
//both SIGUSR1 and SIGTERM signals
void action(int signo) {
    if(signo == SIGUSR1)
        printf("Received SIGUSR1 signal!\n");
    else if(signo == SIGTERM)
    {
        printf("Received SIGTERM signal! Exiting...\n");
        exit(0);
    }
}

int roll_dice(){
    return rand() % 10 + 1;
}

void play_game(char *, int);

int main()
{
    pid_t pid1, pid2;

  //To handle simple signal SIGUSR1
    signal(SIGUSR1, action);

   //To handle terminating sigaction SIGTERM
    /********UNCOMMENT********/
   signal(SIGTERM, action);

    printf("\nThis is a 2-players game with a referee\n");
    if((pid1 = fork()) == 0) play_game("Player 1", 1);
    if((pid2 = fork()) == 0) play_game("Player 2", 2);

    sleep(1);

    while(1)
    {
        printf("Referee: Player 1 plays\n\n");

        kill(pid1, SIGUSR1);
        pause();

        printf("Referee: Player 2 plays\n\n");

        kill(pid2, SIGUSR1);
        pause();
    }
}

void play_game(char *name, int player_number)
{
    int points = 0;
    int dice;

    srand(time(NULL) + player_number);

    while(1)
    {
        pause();

        printf("%s: playing my dice\n", name);
        dice = roll_dice();
        printf("%s: got %d points\n", name, dice);
        points += dice;
        printf("%s: Total so far %d\n\n", name, points);

        sleep(2);

        if(points >= 40)
        {
            printf("%s: Game over, I won!\n", name);
            kill(0, SIGTERM);
        }

        kill(getppid(), SIGUSR1);
    }
}

