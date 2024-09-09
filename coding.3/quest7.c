#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int rc = fork();
	if (rc == 0){
        close(STDOUT_FILENO);
        printf("Child print");
	} else {

	}
	return 0;
}


/*********************************************
   Oluwagbayi Makinde:
   Question 1: "What happens to the print statement?"
   Answer: It does not print anything to the console, as standard output has been closed.
*********************************************/
