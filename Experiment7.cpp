#include <stdio.h>
#include <iostream>
using namespace std;
 
int i, limit, total = 0, x, counter = 0;
int wait_time = 0, turnaround_time = 0, temp[10];

void round_robin_scheduling(int at[], int bt[], int qtime){
    cout<<"\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n";
    for(total = 0, i = 0; x != 0;){
        if(temp[i] <= qtime && temp[i] > 0){
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }else if(temp[i] > 0){
            temp[i] = temp[i] - qtime;
            total = total + qtime;
        }
        if(temp[i] == 0 && counter == 1){
            x--;
            cout<<"\nP"<<i+1<<"\t\t"<<bt[i]<<"\t\t "<<at[i]<<"\t\t\t "<<total - at[i] - bt[i];
            wait_time = wait_time + total - at[i] - bt[i];
            turnaround_time = turnaround_time + total - at[i];
            counter = 0;
        }
        if(i == limit - 1){
            i = 0;
        }else if(at[i + 1] <= total){
            i++;
        }else{
            i = 0;
        }
    }
}

int main(){

    int  arrival_time[10], burst_time[10], time_quantum;
    cout<<"Enter number of Processes: ";
    cin>>limit;
    x = limit;
    for(int i=0; i<limit; i++){
        cout<<"Process "<<i+1<<"\n";
        cout<<"Enter Arrival Time: ";
        cin>>arrival_time[i];
        cout<<"Enter Burst Time: ";
        cin>>burst_time[i];
        cout<<"\n";
        temp[i] = burst_time[i];
    }
    printf("Enter Time Quantum: ");
    cin>>time_quantum;

    round_robin_scheduling(arrival_time, burst_time, time_quantum);

    float average_wait_time, average_turnaround_time;
    average_wait_time = (float)wait_time / limit;
    average_turnaround_time = (float)turnaround_time / limit;

    cout<<"\n\nAverage Waiting Time: "<<average_wait_time;
    cout<<"\nAvg Turnaround Time: "<<average_turnaround_time<<"\n";
    
    return 0;
}