#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter the number of Process : ");
	scanf("%d",&n);
	printf("Enter the Brust time : ");
	for(i=0;i<n;i++){
		printf("p%d:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++){
		pos=1;
		for(j=i+1;j<n;j++){
			if(bt[j]<bt[pos]){
				pos=j;
			}
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
		
		
	}
	wt[0]=0;
	for(j=0;j<i;j++){
		wt[i]+=bt[j];
		total+=wt[i];
	}
	avg_wt=(float)total/n;
	total=0;
	printf("nProcess     Brust_time    waiting_Time       TAT_time \n");
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		total = tat[i];
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
		printf("np%dtt      %dtt      %dttt%d \n",p[i]  ,bt[i],wt[i],tat[i]);
	}
	avg_tat=(float)total/n;
	printf("nnAverage waiting time = %f",avg_wt);
	printf("nnAverage waiting time = %f",avg_tat);
}



