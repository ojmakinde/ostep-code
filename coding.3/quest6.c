#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int rc = fork();
	if (rc == 0){
		printf("Child: goodbye\n");
	} else {
        int wc = waitpid(-1, NULL, 0);
        printf("wait returned %d\n", wc);
		printf("Parent: hello\n");
	}
	return 0;
}


/*********************************************
   Oluwagbayi Makinde:
   Question 1: "Why is waitpid() useful?"
   Answer: Waitpid() can take in the specific pid of the program we want, so it can
   be very useful in different cases.
*********************************************/
