#include <bits/stdc++.h> 
using namespace std; 
  
struct Process{ 
    int pid;
    int bt;
    int at;
}; 

void waitingTime(Process proc[], int n, int wt[]){ 
    int rt[n];
    for (int i = 0; i < n; i++)  rt[i] = proc[i].bt;
    int complete = 0, t = 0, minm = INT_MAX; 
    int least = 0, finish_time; 
    bool check = false;
    while (complete != n){ 
        for(int j = 0; j < n; j++){ 
            if((proc[j].at <= t) && (rt[j] < minm) && rt[j] > 0){ 
                minm = rt[j]; 
                least = j; 
                check = true; 
            }
        }
        if(check == false){ 
            t++; 
            continue; 
        }
        rt[least]--; 
        minm = rt[least]; 
        if(minm == 0)  minm = INT_MAX;
        if(rt[least] == 0){
            complete++; 
            check = false; 
            finish_time = t + 1; 
            wt[least] = finish_time - proc[least].bt - proc[least].at;
            if (wt[least] < 0)  wt[least] = 0; 
        }t++;
    } 
} 

void turnAroundTime(Process proc[], int n, int wt[], int tat[]){
    for (int i = 0; i < n; i++)  tat[i] = proc[i].bt + wt[i]; 
} 
  
void findavgTime(Process proc[], int n){
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingTime(proc, n, wt);
    turnAroundTime(proc, n, wt, tat);
    cout<<" Process\t|"<<" Burst time\t|"<<" Waiting time\t|"<<" Turn around time\n";
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout<<"\t"<<proc[i].pid<<"\t|\t"<<proc[i].bt<<"\t|\t"<< wt[i]<<"\t|\t"<<tat[i]<<"\n";
    }
    cout<<"\nAverage waiting time = "<<(float)total_wt / (float)n; 
    cout<<"\nAverage turn around time = "<<(float)total_tat / (float)n<<"\n";
} 

int main(){
    int n;
    cout<<"Enter number of Processes: ";
    cin>>n;
    Process process[n];
    for(int i=0; i<n; i++){
        cout<<"Process "<<i+1<<"\n";
        cout<<"Enter Process Id: ";
        cin>>process[i].pid;
        cout<<"Enter Arrival Time: ";
        cin>>process[i].at;
        cout<<"Enter Burst Time: ";
        cin>>process[i].bt;
        cout<<"\n";
    }
    findavgTime(process, n);
    return 0;
} 