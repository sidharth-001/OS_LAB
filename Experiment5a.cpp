#include<iostream>
using namespace std;
int process[20][6];

void waitTime(int n, int process[][6]){
    for (int i = 1; i < n ; i++){
        process[i][3] = process[i-1][3] + process[i-1][2];
        process[i][4] = process[i][3] - process[i][1];
        if (process[i][4] < 0)  process[i][4] = 0;
    }
}

void turnAroundTime(int n, int process[][6]){
    for (int i = 0; i < n ; i++)  process[i][5] = process[i][2] + process[i][4];
}

void findavgTime(int n, int process[][6]){
    float avg_wt,avg_tat;
    waitTime(n, process);
    turnAroundTime(n, process);
    int total_wt = 0, total_tat = 0;
    for (int i = 0 ; i < n ; i++){
        total_wt = total_wt + process[i][4];
        total_tat = total_tat + process[i][5];
    }
    avg_wt=(float)total_wt / (float)n;
    avg_tat=(float)total_tat / (float)n;
    cout<<"Average waiting time = "<<avg_wt<<"\n";
    cout<<"Average turnaround time = "<<avg_tat<<"\n";
}


int main(){
    int n;
    cout<<"Enter number of Processes: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Process "<<i+1<<"\n";
        cout<<"Enter Process Id: ";
        cin>>process[i][0];
        cout<<"Enter Arrival Time: ";
        cin>>process[i][1];
        cout<<"Enter Burst Time: ";
        cin>>process[i][2];
    }
    findavgTime(n, process);
    return 0;
}