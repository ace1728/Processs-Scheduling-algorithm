#include <stdio.h> 
#include<math.h> 
#include<string.h> 
#include<limits.h> 
int wt[100],bt[100],at[100],tat[100],n,p[100]; 
float awt[5],atat[5]; 
// we create this file to store all the processes information without slowing down the 
compiler 
// by storing the data in a file and not the i/o buffer or temporary memory 
void create_file_csv(char *filename,int a[][2],int n,int m) 
{ 
printf("\n Creating %s.csv file",filename); 
FILE *fp; 
int i,j; 
filename=strcat(filename,".csv"); 
fp=fopen(filename,"w+"); 
fprintf(fp,"FCFS, SJF, RR, SRTF, Innovative Algo"); 
for(i=0;i<m;i++) 
{ 
fprintf(fp,"\n%d",i+1); 
for(j=0;j<n;j++) 
fprintf(fp,",%d ",a[i][j]); 
} 
fclose(fp); 
printf("\n %sfile created",filename); 
} 
// used to enter the processes and their burst and arrival time 
void input() 
{ 
printf("Enter Number of processes:"); 
scanf("%d",&n); 
int i; 
for(i=0;i<n;i++) 
p[i]=i+1; 
for(i=0;i<n;i++) 
{ 
printf("Enter Burst Time of process %d:",i+1); 
scanf("%d",&bt[i]); 
printf("Enter Arrival Time of process %d:",i+1); 
scanf("%d",&at[i]); 
} 
for(i=0;i<5;i++) 
{ 
awt[i]=0.0; 
atat[i]=0.0; 
} 
} 
//this is used to set the arrival time in increasing order 
void changeArrival() 
{ 
 int a=at[0]; 
 int i; 
 for(i=0;i<n;i++) 
 { 
 if(at[i]<a) 
 a=at[i]; 
 } 
 if(a!=0) 
 { 
 for(i=0;i<n;i++) 
 at[i]=at[i]-a; 
 } 
} 
void fcfs() 
{ 
//set the waiting time of first process to be 0 
wt[0]=0; 
//set the values of burst time ,turn around time and average turn aroundtime to be equal 
atat[0]=tat[0]=bt[0]; 
int btt=bt[0]; 
int i; 
for(i=0;i<n;i++){ 
//calculating the waiting time for the process 
wt[i]=btt-at[i]; 
btt+=bt[i]; 
awt[0]+=wt[i]; //adding the value to average waiting time 
tat[i]= wt[i]+bt[i]; // calculating the turnaround time 
atat[0]+=tat[i]; //adding the value for the calculation of average turnaround time 
} 
//calculating the average calues for turnaround time and waiting time 
atat[0]/=n; 
awt[0]/=n; 
printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n"); 
for(i=0;i<n;i++) 
{ 
printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]); 
} 
} 
void innovative(){ 
int i, total = 0, x, counter = 0, time_quantum; 
int wait_time = 0, turnaround_time = 0, temp[100]; 
x=n; 
for(i = 0; i < n; i++) 
{ 
// used to check if bt of that process is equal to quantum 
//if it is then counter=1 indicating process is completed 
temp[i] = bt[i]; 
} 
// here we find ot the max bt 
int avg,sum=0,max; 
max=bt[0]; 
 for(int i=1; i<n; i++) 
 { sum=sum+bt[i]; 
 if(max<bt[i]) 
 max=bt[i]; 
 } 
 avg=sum/n; 
 //here we calculate the smart time quantum 
 time_quantum=(max+avg)/2; 
 printf(" smart quantum :%d\n",time_quantum); 
printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t WaitingTime\n"); 
for(total = 0, i = 0; x != 0;) 
{ 
if(temp[i] <= time_quantum && temp[i] > 0) 
{ 
total = total + temp[i]; 
temp[i] = 0; 
counter = 1; 
} 
// if the bt > than quantum then temp will hold the remaining bt after one quantum has 
been alotted to it 
else if(temp[i] > 0) 
{ 
temp[i] = temp[i] - time_quantum; 
total = total + time_quantum; 
} 
// if a process is complete this condition is checked by its bt stored in temp =0 and the 
counter flag for keeping track of the completion is 1 
//then we decrease x by 1 we use x as a flag in this loop to only exit when all the processes 
are finished 
if(temp[i] == 0 && counter == 1) 
{ 
x--; 
printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]); 
wait_time = wait_time + total - at[i] - bt[i]; 
turnaround_time = turnaround_time + total - at[i]; 
counter = 0; 
} 
// used to calculate the waiting time by the process by adding the total int to it we kept 
using in the prvious lines to know the time spent for the process 
// and we calculate wt by sub at and bt from sum of wt and total 
// here we set the counter back to zero for the next process we will evaluate 
if(i == n - 1) 
{//if we reach the end of the process array we switch back to the start of the process queue 
by setting i=0 
i=0; 
} 
//we increment to the next process 
else if(at[i+1]<=total) 
{ 
i++; 
} 
else 
{ 
i=0; 
} 
} 
// here we calculate the avg wt and avg tat 
awt[4]=wait_time*1.0/n; 
atat[4]=turnaround_time*1.0/n; 
} 
void rr() 
{ 
int i, total = 0, x, counter = 0, time_quantum; 
int wait_time = 0, turnaround_time = 0, temp[100]; 
x=n; 
for(i = 0; i < n; i++) 
{ 
temp[i] = bt[i]; 
} 
printf("\nEnter Time Quantum:\t"); 
scanf("%d", &time_quantum); 
printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t WaitingTime\n"); 
for(total = 0, i = 0; x != 0;) 
{ 
// used to check if bt of that process is equal to quantum 
//if it is then counter=1 indicating process is completed 
if(temp[i] <= time_quantum && temp[i] > 0) 
{ 
total = total + temp[i]; 
temp[i] = 0; 
counter = 1; 
} 
// if the bt > than quantum then temp will hold the remaining bt after one quantum has 
been alotted to it 
else if(temp[i] > 0) 
{ 
temp[i] = temp[i] - time_quantum; 
total = total + time_quantum; 
} 
// if a process is complete this condition is checked by its bt stored in temp =0 and the 
counter flag for keeping track of the completion is 1 
//then we decrease x by 1 we use x as a flag in this loop to only exit when all the processes 
are finished 
if(temp[i] == 0 && counter == 1) 
{ 
x--; 
printf("Process[%d]\t\t%d\t\t %d\t\t\t %d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]); 
// used to calculate the waiting time by the process by adding the total int to it we kept 
using in the prvious lines to know the time spent for the process 
// and we calculate wt by sub at and bt from sum of wt and total 
wait_time = wait_time + total - at[i] - bt[i]; 
turnaround_time = turnaround_time + total - at[i]; 
// here we set the counter back to zero for the next process we will evaluate 
counter = 0; 
} 
//if we reach the end of the process array we switch back to the start of the process queue 
by setting i=0 
if(i == n - 1) 
{ 
i=0; 
} 
//we increment to the next process 
else if(at[i+1]<=total) 
{ 
i++; 
} 
else 
{ 
i=0; 
} 
} 
// here we calculate the avg wt and avg tat 
awt[2]=wait_time*1.0/n; 
atat[2]=turnaround_time*1.0/n; 
} 
void findWaitingTime(int pid[],int bt[],int at[], int n, int wt[]) 
{ //this function is to calculate the waiting time for SRTF algorithm 
 int rt[n]; 
 // we use rt array for storing remaining time 
 for (int i = 0; i < n; i++) 
 rt[i] = bt[i]; 
//complete is the flag we use for our while loop to keep it running till all processes are 
completed 
 int complete = 0, t = 0, minm = INT_MAX; 
 int shortest = 0, finish_time; 
 int check =0; 
 
 // Process until all processes gets 
 // completed 
 while (complete != n) { 
 for (int j = 0; j < n; j++) { 
 //we use this loop to find out which process had the shortest remaing time 
and store its index in shortest int 
 if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) { 
 minm = rt[j]; 
 shortest = j; 
 check =1; 
 } 
 } 
// if the rt for the process is not shortest then check will be 0 so we increase the t int for 
tracking the time spent with the shortest rt and continue with the algorithm 
 if (check == 0) { 
 t++; 
 continue; 
 } 
 //as we increment the t int we decrease the rt for shortest 
 rt[shortest]--; 
 //now the minm is equated to rt of shortest and checked if it is 0 meaning if the srt 
process is done if it is we increment the complete flag 
 minm = rt[shortest]; 
 if (minm == 0) 
 minm = INT_MAX; 
 //as we increment the complete flag and we put check=0 and minm 
back to the value we initialized it to for the next process 
 if (rt[shortest] == 0) { 
 complete++; 
 check =0; 
 // we calculate the finish time foe that process and equate it to t 
which we used to track time plus 1 
 finish_time = t + 1; 
 // we calculate the wt by sub bt and at from finsh time acting as the 
total time consumed by the process 
 wt[shortest] = finish_time - bt[shortest] - at[shortest]; 
// this is a situation to calc wt back to 0 if by an anamoly in values entered by the user the 
wt becomes negative 
 if (wt[shortest] < 0) 
 wt[shortest] = 0; 
 } 
 t++; } 
} 
void findTurnAroundTime(int bt[], int n, int wt[], int tat[]) 
{ 
 for (int i = 0; i < n; i++) 
 tat[i] = bt[i] + wt[i]; 
} 
 
void srtf(int pid[],int bt[],int at[], int n) 
{ 
 int wt[n], tat[n], total_wt = 0, total_tat = 0; 
 
 findWaitingTime(p,bt,at, n, wt); 
 findTurnAroundTime(bt, n, wt, tat); 
 printf("Processes Burst time Waiting time Turn around time\n"); 
 
 // Calculate total waiting time and 
 // total turnaround time 
 for (int i = 0; i < n; i++) { 
 total_wt = total_wt + wt[i]; 
 total_tat = total_tat + tat[i]; 
 
 printf(" %d \t\t",pid[i]); 
 printf(" %d \t\t",bt[i]); 
 printf(" %d \t\n",tat[i]); 
 } 
double s=(float)total_wt / (float)n; 
 //printf("Average waiting time = %f",s); 
 awt[3]=s; 
 double t=(float)total_tat / (float)n; 
 //printf("Average turn around time = %f ",t); 
 atat[3]=t; 
} 
void display(int c) 
{ 
 
int i; 
printf("Average Waiting Time: %f\nAverage Turn AroundTime:%f",awt[c-1],atat[c-1]); 
} 
void sjf() 
{ 
float wavg=0,tavg=0,tsum=0,wsum=0; 
int i,j,temp,sum=0,ta=0; 
for(i=0;i<n;i++) 
{ 
for(j=0;j<n;j++) 
{ 
if(at[i]<at[j]) 
{ 
//arranged the values according to the ascending order of arrival time 
//swapped the values for the same 
temp=p[j]; 
p[j]=p[i]; 
p[i]=temp; 
temp=at[j]; 
at[j]=at[i]; 
at[i]=temp; 
temp=bt[j]; 
bt[j]=bt[i]; 
bt[i]=temp; 
} 
} 
} 
int btime=0,min,k=1; 
for(j=0;j<n;j++) 
{ 
btime=btime+bt[j]; 
min=bt[k]; //set the value of min to the initial burst time 
for(i=k;i<n;i++) 
{ 
if(btime>=at[i] && bt[i]<min) //compared the processes with the min value set 
{ 
//arranged the values according to the comparison result 
temp=p[k]; 
p[k]=p[i]; 
p[i]=temp; 
temp=at[k]; 
at[k]=at[i]; 
at[i]=temp; 
temp=bt[k]; 
bt[k]=bt[i]; 
bt[i]=temp; 
} 
} 
k++; //increased the value of k 
} 
wt[0]=0; 
for(i=1;i<n;i++) 
{ 
sum=sum+bt[i-1]; //calculated the sum for the average burst time 
wt[i]=sum-at[i]; // calculated the waiting time 
wsum=wsum+wt[i]; //calculating the sum for average waiting time 
} 
awt[1]=(wsum/n); 
for(i=0;i<n;i++) 
{ 
ta=ta+bt[i]; 
tat[i]=ta-at[i]; //calculating the turnaround time 
tsum=tsum+tat[i]; //calculating total turnaround time 
} 
atat[1]=(tsum/n); //calculating average turnaround time 
printf("SR.\tA.T.\tB.T.\tW.T.\tT.A.T.\n"); 
for(i=0;i<n;i++) 
{ 
printf("%3d\t%3d\t%3d\t%3d\t%4d\n",i+1,at[i],bt[i],wt[i],tat[i]); 
} 
} 
int main(){ 
printf("Welcome to CPU Scheduling:\n\n"); 
input(); 
int c,choice; 
changeArrival(); 
printf("Choice\tAlgorithm used\n1\tFCFS Algorithm\n2\tSJF Algorithm\n3\tRound 
robin\n4\tSRTF Algorithm\n5\tOur innovative algorithm\n"); 
do 
{ 
printf("Enter your choice from the above table"); 
scanf("%d",&c); 
switch(c) 
{ 
case 1:fcfs();break; 
case 2:sjf();break; 
case 3:rr();break; 
case 4:srtf(p,bt,at, n);break; 
case 5:innovative();break; 
default: printf("Please enter choice from 1 to 5 only\n");break; 
} 
display(c); 
printf("\n\nEnter 1 to continue 0 to stop"); 
scanf("%d",&choice); 
}while(choice==1); 
int a[5][2],i; 
for(i=0;i<5;i++) 
{ 
a[i][0]=awt[i]; 
a[i][1]=atat[i]; 
} 
create_file_csv("schedule",a,5,2); 
}
