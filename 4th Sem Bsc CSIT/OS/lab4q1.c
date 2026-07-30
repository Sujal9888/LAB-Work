#include<stdio.h>
#include<pthread.h>
#include<time.h>

void *show(void *u){
	printf("New Thread\n");
	return NULL;
}

int main(){
	pthread_t tid;
	time_t t;

	time(&t);
	printf("Date: %s",ctime(&t));

	if(pthread_create(&tid, NULL, &show, NULL)!=0){
		perror("Failed to create thread.");
	}
	printf("Main Thread...\n");
	pthread_join(tid, NULL);
	return 0;
}

