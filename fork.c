//exp write a c program to demonstrate the use of fork() system call 

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	int n;
	printf("fork function is used to divide the process p1 into two process p1,p2 it returns 0 when successfully ");
	fork();
	for(int i=0;i<100;i++){
		printf("%d\n",getpid());
	}
	printf("\n");
}
