#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
void main()
	{
	int a,b,c;
	pid_t id=fork();
	
	if(id==0)
		{
		printf("enter the number\n");
		scanf("%d",&a);
		if(a%2==0)
			{
			printf("number is even\n");
			}
		else
			{
			printf("number is odd\n");
			}
		}
	else if(id>0)
		{
		wait(NULL);
		printf("enter 2 numbers\n");
		scanf("%d",&b);
		scanf("%d",&c);
		if(b>c)
			{
			printf("%d is greatest",b);
			}
		else
			{
			printf("%d is greatest",c);
			}
		}
	else
		{
		printf("failure\n");
		}
		
	}
