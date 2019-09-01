#include<stdio.h>
int main() {
	system("clear");
	int pid=fork();
	int pid1 , s;
	if(pid > 0) {
		int pid1 = fork();
		if(pid1 == 0) {
			printf("\nChild2 Id\t:\t%d\nParent Id\t:\t%d\n",getpid(),getppid());
		}
		else {
			wait((void*)&s);
			printf("\nParent Id\t:\t%d\nGrandParent Id\t:\t%d\n",getpid(),getppid());
		}
	}
	else {
		printf("\nChild1 Id\t:\t%d\nParent Id\t:\t%d\n",getpid(),getppid());
	}
}
