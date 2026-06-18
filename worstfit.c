#include<stdio.h>
void main()
	{
	int p,b,psize[20],f[20],i,j,temp,flag,big;
	printf("enter no of processes:");
	scanf("%d",&p);
	printf("enter size of processes:\n");
	for(i=0;i<p;i++)
		{
		printf("P %d: ",i);
		scanf("%d",&psize[i]);
		}
	printf("enter no of blocks: ");
	scanf("%d",&b);
	printf("enter size of blocks:\n");
	for(i=0;i<b;i++)
		{
		printf("B %d: ",i);
		scanf("%d",&f[i]);
		}
	printf("process no\t\tprocess size\t\tblock no\t\tblock size\t\tfragment\n");
	for(i=0;i<p;i++)
		{
		flag=0;
		big=-1;
		for(j=0;j<b;j++)
			{
			if(psize[i]<=f[j])
				{
				if(big==-1||f[j]>f[big])
					{
					big=j;
					}
				}
			}
		if(big!=-1)
			{
			flag=1;
			temp=f[big];
			f[big]=f[big]-psize[i];
			printf("P %d\t\t\t%d\t\t\t B%d\t\t\t%d\t\t\t%d\n",i,psize[i],big,temp,f[big]);
			}
		if(flag==0)
			{
			printf("P %d\t\t\t%d\t\t\t not\t\t\t not\t\t\t not\n",i,psize[i]);
			break;
			}
		}
	}
