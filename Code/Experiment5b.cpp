#include<iostream>
using namespace std;
int process[20][6];

void sortProcess(int n, int process[][6]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(process[j][1] > process[j+1][1]){
                for(int k=0; k<5; k++){
                    int temp = process[j][k];
                    process[j][k] = process[j+1][k];
                    process[j+1][k] = temp;
                }
            }
        }
    }
}

void calBurst(int n, int process[][6]){
    int val, key;
    process[0][3] = process[0][1] + process[0][2];
    process[0][5] = process[0][3] - process[0][1];
    process[0][4] = process[0][5] - process[0][2];
    for(int i=1; i<n; i++){
        val = process[i-1][3];
        int low = process[i][2];
        for(int j=i; j<n; j++){
            if(val >= process[j][1] && low >= process[j][2]){
                low = process[j][2];
                key = j;
            }
        }
        process[key][3] = val + process[key][2];
        process[key][5] = process[key][3] - process[key][1];
        process[key][4] = process[key][5] - process[key][2];
        for(int k=0; k<6; k++){
            int temp = process[key][k];
            process[key][k] = process[i][k];
            process[i][k] = temp;
        }
    }
}


int main(){
    int n;
    float avg_wt,avg_tat;
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
    sortProcess(n, process);
    calBurst(n, process);
    cout<<"After calculation order is:\n";
    cout<<"  Process ID\t|  Arrival Time\t|  Burst Time\n";
    for(int i=0; i<n; i++){
        cout<<"\t"<<process[i][0]<<"\t|\t"<<process[i][1]<<"\t|\t"<<process[i][2]<<"\n";
    }
    float total=0;
    for(int i=0;i<n;i++)  total=total+process[i][4];
    avg_wt=(float)total/n;
    total=0;
    for(int i=0;i<n;i++)  total=total+process[i][5];
    avg_tat=(float)total/n;
    cout<<"Average waiting time = "<<avg_wt<<"\n";
    cout<<"Average turnaround time = "<<avg_tat<<"\n";
    return 0;
}