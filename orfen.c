#include<stdio.h>
#include<unistd.h>
int main(){
	int x=0;
	 x=fork();
	if(x!=0){
		printf("parent\n");
    exit(0);
	}
	else{
		printf("child\n");
		sleep(2);
	}
}
