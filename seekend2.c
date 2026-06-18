#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
void main()
	{
	char buff[20];
	int fd1=open("f1.txt",O_RDONLY);
	lseek(fd1,10,SEEK_SET);
	lseek(fd1,-6,SEEK_END);
	read(fd1,buff,15);
	write(1,buff,15);
	close(fd1);
	}
