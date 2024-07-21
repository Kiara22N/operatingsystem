# define BUFFERSIZE 10;
int mutex, n, empty, full=0,item, item1;
int buffer[20];
int in=0,out=0,mutex=1;
void wait(int s)
{
while(s<0)
{
printf("\ Cannot add an item \n");
exit(0);
}
s--;
}
void signal(int s)
{
s++;
}
void producer()
{
do{
wait ( empty );
wait ( mutex );
printf("\n Producer produces an item:");
scanf("%d", &item);
buffer[in]=item;
in=in+1;
signal(mutex);
signal(full);
}
while(in<n);
}
void cosumer()
{
do{
wait(full);
wait(mutex);
item1=buffer[out];
printf("\n Consumed item = %d",item1);
out = out+1;
signal(mutex);
signal(mutex);
}
while(out<n);
}
void main(){
printf("\n Enter the value of n :");
scanf("%d",&n) ;
empty = n;
while(in<n)
producer();
while(in!=out)
cosumer();
}