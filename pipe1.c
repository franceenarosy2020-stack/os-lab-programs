
#include<stdio.h>        
 #include <fcntl.h>           
 #include <unistd.h>
 void main()
 	{
 	int fd[2],n;
 	pid_t p;
 	char b[100];
 	pipe(fd);
 	p=fork();
 	if(p>0)
 		{
 		printf("parent writing\n");
 		write(fd[1],"hello\n",5);
 		}
 	else
 		{
 		n=read(fd[0],b,100);
 		write(1,b,n);
 		}
 	}
