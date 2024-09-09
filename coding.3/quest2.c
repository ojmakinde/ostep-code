#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    
    if (fd < 0) {
        exit(1);
    }

    printf("File opened with file descriptor: %d\n", fd);

    int rc = fork();
    if (rc == 0) {
        printf("Child process writing to file\n");
        const char *child_msg = "This is the child process\n";
        write(fd, child_msg, strlen(child_msg));
    } else {
        printf("Parent process writing to file\n");
        const char *parent_msg = "This is the parent process\n";
        write(fd, parent_msg, strlen(parent_msg));
    }
    
    return 0;
}

/*********************************************
   Oluwagbayi Makinde:
   Question 1: "Can both access the file descriptor"
   Answer: Yes, both the parent and child process can access the descriptor
   Question 2: "What happens during a concurrent write?"
   Answer: Both the parent and child write. It seems, however, that the parent writes to
   the file first, as shown by the print statement.
*********************************************/