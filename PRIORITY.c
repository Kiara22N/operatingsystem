#include<stdio.h>
void main()
{
int wt[20]={0},bt[20]={0},tat[20]={0},prty[20]={0},i,swt=0,stat=0,max,j,n,m,p[20],x;
float awt,atat;
printf("Enter the no. of processes:");
scanf("%d",&n);
printf("Enter the burst times:");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
printf("\nEnter the priorities:");
for(i=0;i<n;i++)
{
scanf("%d",&prty[i]);
}
printf("Enter the processes number:");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(prty[i]>prty[j])
{
max=prty[i];
prty[i]=prty[j];
prty[j]=max;
m=p[i];
p[i]=p[j];
p[j]=m;
x=bt[i];
bt[i]=bt[j];
bt[j]=x;
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
for(i=1;i<n;i++)
{
wt[i]=bt[i-1]+wt[i-1];
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
printf("\n---------------------------------------");
for(i=0;i<n;i++)
{
printf("\n P%d \t%d\t%d \t%d",p[i],bt[i],wt[i],tat[i]);
}
printf("\n---------------------------------------");
printf("\n \t(AWT)%f %f(ATAT)\n",awt,atat);
printf("\n---------------------------------------");
}
