#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];

    pipe(pipefd);

    int child_1 = fork();

    if (child_1 == 0) {  
        close(pipefd[0]);
        const char *msg = "Message from child 1\n";
        write(pipefd[1], msg, strlen(msg)); 

        close(pipefd[1]);
        exit(0);
    }

    // second child
    int child_2 = fork();

    if (child_2 == 0) {  
        close(pipefd[1]);
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child 2 received: %s", buffer);

        exit(0); 
    }
    return 0;
}

/*********************************************
   Oluwagbayi Makinde: No question
*********************************************/
