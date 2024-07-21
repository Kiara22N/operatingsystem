#include<stdio.h>
void main()
{
int p[20],bt[20]={0},tat[20]={0},wt[20]={0},i,temp=0,ct[20]={0},max,stat=0,swt=0,n,tmslc,j;
float awt, atat;
printf("Enter the no of processes:");
scanf("%d",&n);
printf("Enter the processes number:");
for(i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
printf("Enter the burst times:");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
ct[i]=bt[i];
}
printf("Enter the tmslc:");
scanf("%d",&tmslc);
max=bt[0];
for(i=1;i<n;i++)
{
if(max<bt[i])
max=bt[i];
}
for(j=0;j<(max/tmslc)+1;j++)
{
for(i=0;i<n;i++)
{
if(bt[i]!=0)
{
if(bt[i]<=tmslc)
{
tat[i]=temp+bt[i];
temp=temp+bt[i];
bt[i]=0;
}
else
{
bt[i]=bt[i]-tmslc;
temp=temp+tmslc;
}
}
}
}
for(i=0;i<n;i++)
{
wt[i]=tat[i]-ct[i];
stat+=tat[i];
swt+=wt[i];
}
atat=(float)stat/n;
awt=(float)swt/n;
printf("Process\tBT\tWT\tTAT");
printf("\n---------------------------------------");
for(i=0;i<n;i++)
{
printf("\n P%d \t%d\t%d \t%d",p[i],ct[i],wt[i],tat[i]);
}
printf("\n---------------------------------------");
printf("\n \t(AWT)%f %f(ATAT)\n",awt,atat);
printf("\n---------------------------------------");
}
