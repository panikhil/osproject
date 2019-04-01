#include<stdio.h>
#include<stdlib.h> 

struct process{
	int name;	//stores the process name as integer value 
	float bt;	//the time the process will take in CPU
	float at;	//the time when the process arrives into the queue
	float status;	//tell the status of the process whether done or still not done
	float wt;//the time proces waits to gets executed
	float tat;//the total time taken from getting to ready queue to finnaly getting executed
	
};
void schedule(struct process proc[],int num,int sum){
	int i,j;
	float f,avgWaitingTime=0,avgtat=0;
	sort(proc,num);//sort according to the process arrival time
	printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
	for(f=proc[0].at;f<(float)sum;){
		float pr=-9999;//priority
		int nxt;//hold the the next process
		float temp;	
		for(i=0;i<num;i++){
			if(proc[i].at<=f && proc[i].status!=1){
				temp=(proc[i].bt + (f - proc[i].at)) / proc[i].bt;
				if(pr<temp){
					pr=temp;
					nxt=i;
				}
			}
		}
		f=proc[nxt].bt+f;
		//waiting time
		proc[nxt].wt=f-(proc[nxt].at)-(proc[nxt].bt);
		//Turn around time
		proc[nxt].tat=f-proc[nxt].at;
		//average waiting time
		avgWaitingTime+=proc[nxt].wt;
		//average turn around time
		avgtat+=proc[nxt].tat;
		//update status
		proc[nxt].status=1;
		
		printf("p%d\t%f\t%f",proc[nxt].name,proc[nxt].bt,proc[nxt].at);
		printf("\t%f\t%f\n",proc[nxt].wt,proc[nxt].tat);
		
	}
	printf("Average waiting time=%f\n",avgWaitingTime/num);
	printf("Average turn-around time=%f\n",avgtat/num);
	
}


int main(){
	int i;//loop variable
	float arrival,burst,sum=0;
	static int num;//holds number of process
	struct process proc[10];//array of struct to hold multiple propeties of a single process

	printf("Enter the number of process:");
	scanf("%d",&num);
	
	printf("\nNow, enter the data for the %d processes:\n",num);
	for(i=0;i<num;i++){
		
		proc[i].name=i+1;
		printf("Process p%d\n",proc[i].name);
		
		printf("Burst time:");
		scanf("%f",&burst);
		proc[i].bt=burst;
		
		printf("Arrival time:");
		scanf("%f",&arrival);
		proc[i].at=arrival;
		
		proc[i].status=0;
		sum+=proc[i].bt;

		printf("\n");
	} 	
   schedule(proc,num,sum);
	
}
