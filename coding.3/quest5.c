#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rc = fork();
    if (rc == 0) {
        // Child process
        printf("Child process executing ls with exec()\n");

        execl("ls", "ls", "-l", NULL);

        char *env[] = {"HOME=/usr/home", "LOGNAME=home", NULL};
        execle("ls", "ls", "-l", NULL, env);

        execlp("ls", "ls", "-l", NULL);

        char *args[] = {"ls", "-l", NULL};
        execv("ls", args);

        exit(1);
    } else if (rc > 0) {
        printf("Parent process finished\n");
    }

    return 0;
}

/*********************************************
   Oluwagbayi Makinde:
   Question 1: "Why are there so many variants?"
   Answer: There are so many variants because each exec provides a different way to specify the calling program and its args
*********************************************/
