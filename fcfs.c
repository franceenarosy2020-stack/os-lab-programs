# include <stdio.h>
void main()
{
      int n;
      float avgt,avgw;
      printf("Enter no.of process:\n");
      scanf("%d",&n);
      int r[n][6],i,j=0,t=0,w=0;
      for(i=0;i<n;i++)
      {
            printf("Enter the arrival and burst time of %d process\n",i+1);
            r[i][0]=i+1;
            scanf("%d %d",&r[i][1],&r[i][2]);
      }      
       for(i=0;i<n;i++)      
       {    
            r[i][3]=r[i][2]+j;
              j=r[i][3];
            r[i][4]=r[i][3]-r[i][1];
            r[i][5]=r[i][4]-r[i][2];
       }
      for(i=0;i<n;i++)
      {
            t=t+r[i][4];
            w=w+r[i][5];
      }
      avgt=(float)t/n;
      avgw=(float)w/n;
      printf("TABLE\n");
      printf("process\tAT\tBT \t CT\t TT\t WT\n");
      for(i=0;i<n;i++)
      {
            printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",r[i][0],r[i][1],r[i][2],r[i][3],r[i][4],r[i][5]);
      }
      printf("Average turnarounfd time = %.2f",avgt);
      printf("Average waiting time = %.2f",avgw);
}
