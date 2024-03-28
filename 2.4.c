#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int i;
char name[20];

void childTask(){
printf("\nHello I am child number %d, PPID=%d, PID=%d\n", i,getppid(),getpid());
printf("Please enter name: ");
scanf("%s", name);
printf("The name is %s \n", name);
}

void parentTask(){
printf("Hello I am the parent, PID=%d\n", getpid());
}

int main (void){

for (i=1; i<5; i++){
	pid_t pid = fork();
	
	if (pid==0){
		childTask();
		exit (EXIT_SUCCESS);
	}
	else{
		parentTask();
		wait(NULL);
	}
}
printf("Job is done.\n");
return EXIT_SUCCESS;
}
