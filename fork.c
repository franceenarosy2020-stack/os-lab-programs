#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
void main()
	{
	pid_t id=fork();
	if(id==0)
		{
		printf("hello\n");
		printf("parent id :%d",getppid());
		printf("process id :%d",getpid());
		}
	else if(id<0)
		{
		printf("failure\n");
		}
	else
		{
		printf("hi\n");
		printf("parent id :%d",getppid());
		printf("process id :%d",getpid());
		}
	}
