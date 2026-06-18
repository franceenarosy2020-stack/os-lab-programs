#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<semaphore.h>
#include<pthread.h>
int in=0,out=0,i,j,shmid;
char buff[15];
void *shmem;
pthread_mutex_t mutex;
void *writer(void* p1no)
	{
	pthread_mutex_lock(&mutex);
	shmid=shmget((key_t)2346,1024,0666|IPC_CREAT);
	printf("Key of shared memory is: %d\n",shmid);
	shmem=shmat(shmid,NULL,0);
	printf("Process attatched: %p\n",shmem);
	printf("Enter some data to write: \n");
	read(0,buff,15);
	strcpy(shmem,buff);
	printf("Write done\n");
	pthread_mutex_unlock(&mutex);
	}
void* reader(void* p2no)
	{
	pthread_mutex_lock(&mutex);
	shmid=shmget((key_t)2346,1024,0666);
	printf("Key of shared memory is: %d ",shmid);
	shmem=shmat(shmid,NULL,0);
	printf("\nData read from shared memory: %s",(char *)shmem);
	pthread_mutex_unlock(&mutex);
	}
void main()
	{
	pthread_t p1,p2;
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&p1,NULL,(void *)writer,NULL);
	pthread_create(&p2,NULL,(void *)reader,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_mutex_destroy(&mutex);
	}
