#include<stdio.h>
void main()
	{
	int p,b,psize[20],f[20],i,j,temp,flag,best;
	printf("enter no of processes:");
	scanf("%d",&p);
	printf("enter size of processes:\n");
	for(i=0;i<p;i++)
		{
		printf("P %d: ",i);
		scanf("%d",&psize[i]);
		}
	printf("enter no of blocks:");
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
		best=-1;
		for(j=0;j<b;j++)
			{
			if(psize[i]<=f[j])
				{
				if(best==-1||f[j]<f[best])
					{
					best=j;
					}
				}
			}
		if(best!=-1)
			{
			flag=1;
			temp=f[best];
			f[best]=f[best]-psize[i];
			printf("P %d\t\t\t%d\t\t\t B %d\t\t\t%d\t\t\t%d\n",i,psize[i],best,temp,f[best]);
			}
		if(flag==0)
			{
			printf("P %d\t\t\t%d\t\t\tnot\t\t\tnot\t\t\tnot\n",i,psize[i]);
			break;
			}
		}
	}
