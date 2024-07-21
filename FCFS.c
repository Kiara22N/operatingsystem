#include<stdio.h>
void main()
{
int wt[20]={0},bt[20]={0},tat[20]={0},n,i,swt=0,stat=0;
float awt,atat;
printf("Enter the no of processes:");
scanf("%d",&n);
printf("Enter the burst times: ");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
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
}
awt=swt/n;
for(i=0;i<n;i++)
{
stat=stat+tat[i];
}
atat=stat/n;
printf("Process\tBT\tWT\tTAT");
printf("\n-----------------------------------");
for(i=0;i<n;i++)
{
printf("\n P%d \t%d\t%d \t%d",i+1,bt[i], wt[i], tat[i]);
}
printf("\n-----------------------------------");
printf("\t(ATAT)%f \t(AWT)%f\n",atat,awt);
printf("-----------------------------------");
}
