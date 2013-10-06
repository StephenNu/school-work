
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void readerChild(int fd);

int main(int argc, char *argv[]){

    int fd1, fd2;
    char ch;

    unlink("./tmp/nuskos1");  /* delete any previous FIFO */
    unlink("./tmp/nuskos2");

    if(mkfifo("./tmp/nuskos1", 0777)){ //use your user ID
        perror("main,1");
        exit(1);
    }

    if(mkfifo("./tmp/nuskos2", 0777)){
        perror("main,2");
        exit(1);
    }

    fprintf(stderr, "Waiting for a friend to chat\n");

    fd1 = open("./tmp/nuskos1", O_RDONLY);
    if (!fork())
    {
        readerChild(fd1);
	exit(0);
    }

    fprintf(stderr, "You have got a friend:\n");
    fprintf(stderr, "    Your messages                                   Friend messages\n");
    fprintf(stderr, "-------------------------------------------------------------------------------\n");

    fd2 = open("./tmp/nuskos2", O_WRONLY);

    while(read(0, &ch, 1) == 1)
	    write(fd2, &ch, 1);

}

void readerChild(int fd){
    char  ch, blanks[55]="                                               |  ";
    int flag = 1;

    while(read(fd, &ch, 1) == 1){
        if(flag){
            flag = 0;
            write(1, blanks, sizeof(blanks));
        }
        write(1, &ch, 1);
        if(ch == '\n') flag = 1;
    }

    close(fd);
}
