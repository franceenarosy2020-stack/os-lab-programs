#include<fcntl.h>
#include<unistd.h>
void main()
	{
	int fd1,fd2,n;
	char b[20];
	fd1=open("t5.txt",O_RDONLY);
	//fd2=creat("t6.txt",0777);
	fd2=open("t6.txt",O_WRONLY|O_APPEND,0777);
	n=read(fd1,b,20);
	write(fd2,b,n);
	close(fd1);
	close(fd2);
	}
