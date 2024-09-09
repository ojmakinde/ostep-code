#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int temp_var = 500;
	int rc = fork();
	if (rc == 0){
		temp_var = 200;
		printf("Child: temp_var = %d\n", temp_var);
	} else {
		printf("Parent: temp_var = %d\n", temp_var);
	}
	return 0;
}

/*********************************************
   Oluwagbayi Makinde:
   Question 1: "What value is the variable in the child process"
   Answer: The variable in the child process is the same as its parent process.
   Question 2: "What happens to the variable when both the child and parent change
the value of x?"
	Answer: The child and parent both assign the variable to a new value and print out their different values.
*********************************************/

