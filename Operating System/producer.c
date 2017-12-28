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
	int a[5]={1,2,3,4,5};
	shm_fd=shm_open(mem,O_CREAT|O_RDWR,0666);
	ftruncate(shm_fd,size);
	ptr=mmap(0,size,PROT_WRITE|PROT_READ,MAP_SHARED,shm_fd,0);
	f=ptr;
	ptr+=2;
	int i;
	sprintf((char*)f,"%s","0");
	for(i=0;i<5;i++)
	{
		while(strcmp((char*)f,"1")==0);
		sprintf(ptr,"%c",a[i]);
		printf("\nProduced\t:\t%d\n",*(int*)ptr);
		sprintf(f,"1");
		sleep(2);
	}
	return 0;
}
