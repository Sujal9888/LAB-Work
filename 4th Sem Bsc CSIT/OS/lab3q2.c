#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	pid_t pid = fork();
	if(pid ==-1){
		printf("Fork Failed\n");
		exit(0);
	}
	if(pid ==0){
		printf("Hello I am a Child Process.\n");
		printf("Process ID: %d \n", getpid());
		printf("The process ID of my Parent Process is %d \n", getppid());
		fflush(stdout);
		sleep(3);
	}
	else{
		wait(NULL);
		printf("Hello from Parent Process \n");
		printf("Process ID: %d \n", getpid());
		fflush(stdout);
	}
}
