
#include<stdio.h>
void main()
{
int wt[20] ={0}, bt[20]={0}, tat[20]={0}, i, swt=0, stat=0, max, j,
n, p[20],m;
float awt,atat;
printf("Enter the no of processes:");
scanf("%d",&n);
printf("Enter the burst times: ");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
printf("Enter the processes number: ");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(bt[i]>bt[j])
{
max=bt[i];
m=p[i];
bt[i]=bt[j];
p[i]=p[j];
bt[j]=max;
p[j]=m;
}
}
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=bt[i-1]+wt[i-1];
}
for(i=0;i<n;i++)
{
tat[i]=wt[i]+bt[i];
}
for(i=0;i<n;i++)
{
swt=swt+wt[i];
stat=stat+tat[i];
}
awt=swt/n;
atat=stat/n;
printf("Process\tBT\tWT\tTAT");
printf("\n-----------------------------------");
for(i=0;i<n;i++)
{
printf("\n %d \t%d\t%d \t%d",p[i],bt[i], wt[i], tat[i]);
}
printf("\n-----------------------------------");
printf("\n \t(ATAT)%f %f(AWT)\n",atat,awt);
printf("-----------------------------------");
}
