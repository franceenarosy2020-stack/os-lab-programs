#include<stdio.h>
#include<unistd.h>
void main()
	{
	int pipefds1[2],pipefds2[2];
	pid_t pid;
	int rs1,rs2;
	char pipe1WriteMessage[]="hi";
	char pipe2WriteMessage[]="hello";
	char readMessage[20];
	rs1=pipe(pipefds1);
	if(rs1==-1)
		{
		printf("unable to create pipe1!\n");
		return;
		}
	rs2=pipe(pipefds2);
	if(rs2==-1)
		{
		printf("unable to create pipe2!\n");
		return;
		}
	pid=fork();
	if(pid!=0)
		{
		close(pipefds1[0]);
		close(pipefds2[1]);
		printf("in parent,writing to pipe1.Message is: %s \n",pipe1WriteMessage);
		write(pipefds1[1],pipe1WriteMessage,sizeof(pipe1WriteMessage));
		printf("in parent,reading from pipe2.Message is:");
		read(pipefds2[0],readMessage,sizeof(readMessage));
		printf("%s\n",readMessage);
		}
	else
		{
		close(pipefds1[1]);
		close(pipefds2[0]);
		printf("in child,reading from pipe1.Message is:");
		read(pipefds1[0],readMessage,sizeof(readMessage));
		printf("%s\n",readMessage);
		printf("in child,writing to pipe2.Message is: %s \n",pipe2WriteMessage);
		write(pipefds2[1],pipe2WriteMessage,sizeof(pipe2WriteMessage));
		}
	}
