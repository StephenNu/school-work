#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>


int read_args(char *, char *[]);


int main(int argc, char *argv[]){
	pid_t pid;
	char line[255];
	char *arg_list[20];
	int ampersand, status;
	printf("This program executes commands/programs for you\n");
	while(1)
	{
		printf("\nEnter a command with its arguments [CTR-C to exit]@ ");
		fgets(line, 255, stdin);
		arg_list[0] = NULL;
		ampersand = read_args(line, arg_list);
		if(arg_list[0] != NULL)
		{
			if((pid = fork()) == -1)
			{
				perror("Impossible to fork");
				exit(1);
			}
			if(pid > 0)
			{ //This is the parent
				if(ampersand)
				{
					printf("Process [%d] running in background...\n", pid);
					waitpid(pid,&status,WNOHANG);
				}
				else
				{
					printf("Process [%d] running in foreground...\n",pid);
					waitpid(pid, &status, 0);
				}
			}
			else
			{
			// this is the child
				if(execvp( arg_list[0], arg_list) == -1 )
				{
					perror("Unable to execute command\n");
					exit(22);
				}
			}
		}
	}//while
}
int read_args(char *line, char* arg_list[])
{
	int arg_cnt = 0, found = 0;
	char *token;
	/* extract first token from line sequence */
	token = strtok(line, " \n");
	while(token != NULL)
	{
		arg_list[arg_cnt] = token;
		arg_cnt++;
		/* extract string from string sequence */
		token = strtok(NULL, " \n");
	}
	/*last token is now stored in arg_list[arg_cnt - 1]*/
	if (arg_list[0] != NULL )
	{
		/* if the last token is & */
		if ( !strcmp( arg_list[arg_cnt - 1], "&") )
		{
			found = 1;
			arg_list[arg_cnt - 1] = NULL;
		}
		else
			arg_list[arg_cnt] = NULL;
	}
	return(found);
}

