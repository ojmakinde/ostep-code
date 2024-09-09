#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){

	int rc = fork();
	if (rc == 0){
		printf("Child: goodbye\n");
	} else {
		printf("Parent: hello\n");
	}
	return 0;
}

/*********************************************
   Oluwagbayi Makinde:
   Question 1: "Can you make the child process print first?"
   Answer: Without using wait, or any other sleeping command like sleep or spin,
   it does not seem like I can ensure the child process prints first.
*********************************************/

