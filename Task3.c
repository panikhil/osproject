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
void sort(struct process proc[],int num){
	int i,j;//iterative variables
	struct process temp;//a temp variable od struct process type so swap the entire process all together
	for(i=0;i<num-1;i++)//selection sort 
    {
        for(j=i+1;j<num;j++)
        {
            if(proc[i].at>proc[j].at){
				//swap the process with lesser arrival time
                temp=proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
			}
        }
        
 		
    }
    
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
   sort(proc,num);
	
}
