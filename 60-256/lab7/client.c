#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void readerChild(int fd);

int main(){

    int fd1, fd2;
    char ch = 'a';



    fprintf(stderr, "You have got a friend:\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");

    while (1)
    {
	    fd1 = open("./tmp/nuskos1", O_WRONLY);
	    fd2 = open("./tmp/nuskos2", O_RDONLY);
	    	if (!fork())
		{
			readerChild(fd2);
			exit(0);
		}

	    while (read(0, &ch, 1) == 1)
		    write(fd1, &ch, 1);
    }
}

void readerChild(int fd){
    char  ch, blanks[55]="                                               |  ";
    int flag = 1;
    while(read(fd, &ch, 1) == 1)
    {
	    if (flag)
	    {
		    flag = 0;
		    write(1, blanks, sizeof(blanks));
	    }
	    write(1, &ch, 1);
	    if (ch == '\n')
	    {
		    flag = 1;
	    }
    }
    close(fd);
}
