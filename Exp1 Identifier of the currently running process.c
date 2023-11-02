#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	printf("Process Id : %d\n",getpid());
	printf("Parent Process Id : %d\n",getpid());
	return 0;
}
