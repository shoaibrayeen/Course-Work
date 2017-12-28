#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/shm.h>
int main()
{
	system("clear");
	const int size=128;
	const char* mem="OS";
	void *ptr,*f;
	int shm_fd;
	shm_fd=shm_open(mem,O_RDWR,0666);
	ptr=mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
	f=ptr;
	ptr+=2;
	int i;
	for(i=0;i<5;i++)
	{
		while(strcmp((char*)f,"0")==0);
		printf("\nConsumed\t:\t%d\n",*(int*)ptr);
		sprintf((char*)f,"0");
	}
	shm_unlink(mem);
	return 0;
}
