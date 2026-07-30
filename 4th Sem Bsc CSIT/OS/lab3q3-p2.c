#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	char *args[]={"./p1", NULL};
	printf("HI, This is Process 2: Executing Process 1...\n");
	fflush(stdout);
	execv("./p1", args);
	perror("Execution Failed");
	return 1;
}
