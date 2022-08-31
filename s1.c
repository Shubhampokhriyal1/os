//write a c program in which the parent process computes the sum off even and child process computes the sum of odd numbers stored in array first ,the child process should print its oun process ie sum off odd numbers then the parent  
#include<stdio.h>

#include <unistd.h>
int main(){
	int n=10,sum=0,sum1=0;
	printf("fo ");
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	
	int k=fork();
	if(k>0){
		for(int i=0;i<n;i++){
			if(arr[i]%2==0){
				sum+=arr[i];
			}
		}
		printf("%d\n",sum);
	}
	else{
		for(int i=0;i<n;i++){
			if(arr[i]%2==1){
				sum1+=arr[i];
			}
		}
		printf("%d\n",sum1);
	}
	printf("\n");
return 0;
}


