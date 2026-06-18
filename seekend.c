#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
void main()
	{
	char buff[20];
	int fd1=open("f1.txt",O_RDONLY);
	lseek(fd1,-6,SEEK_END);
	read(fd1,buff,5);
	write(1,buff,5);
	close(fd1);
	}
