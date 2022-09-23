#include <stdio.h>
#include <stdlib.h>
struct gp{
     int pid;
     int at;
     int bt;
     int ct,tat,wt; 
};
int com(const void *p, const void *q)
{
	int l = ((struct gp *)p)->at;
	int r = ((struct gp *)q)->at;
	return (l - r);
}
int com1(const void *p, const void *q)
{
	int l = ((struct gp *)p)->pid;
	int r = ((struct gp *)q)->pid;
	return (l - r);
}
int main(){
     int n;
     printf("Enter number of processes\n");
     scanf("%d",&n);
     struct gp arr[n],t;
     printf("Enter Arrival and Burst Time\n");
     for(int i=0;i<n;i++){
     arr[i].pid=i+1;
     scanf("%d%d",&arr[i].at,&arr[i].bt);
     }
     qsort((void*)arr, n, sizeof(arr[0]), com);
     int sum=0;
     arr[0].ct=arr[0].at+arr[0].bt;
     arr[0].tat= arr[0].ct-arr[0].at;
     arr[0].wt=arr[0].tat-arr[0].bt;
     int sum_tat=arr[0].tat;
     int sum_wait=arr[0].wt;
     int rt=arr[0].ct-arr[0].bt;
     for(int i=1;i<n;i++){
          if(arr[i].at>=arr[i-1].ct) arr[i].ct=arr[i].at+arr[i].bt;
          else arr[i].ct=arr[i-1].ct+arr[i].bt;
          
          arr[i].tat= arr[i].ct-arr[i].at;
          arr[i].wt=arr[i].tat-arr[i].bt;
          sum_tat+=arr[i].tat;
          sum_wait=arr[i].wt;
          rt+=arr[i].ct-arr[i].bt;
     }
     
     qsort((void*)arr, n, sizeof(arr[0]), com1);
     printf("pid\tat\tbt\tct\ttat\twt\n");
     for(int i=0;i<n;i++){
          printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].wt);
     }
     
     
     printf("total turn around :%d \n total wait :%d \n rt : %d \n",sum_tat,sum_wait,rt);
     return 0;
}
