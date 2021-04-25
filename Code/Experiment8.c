#include <stdio.h>
 
int current[5][5], maximum_claim[5][5], available[5];
int processes,resources;
int need[5][5];
int i, j, k, counter = 0;
int seq[5];

void isSafe(){

    for (i=0; i<processes; ++i){
        for (int j = 0; j < resources; ++j){
            need[i][j] = maximum_claim[i][j] - current[i][j];
        }
    }

    int finish[i];
    for (i=0; i<processes; ++i)
        finish[i] = 0;

    int work[resources];
    for (i=0; i<resources; ++i)
        work[i] = available[i];

    while(counter<processes){
        int p;
        int found = 0;
        for (p=0; p<processes; ++p){
            if(finish[p] == 0){
                for (j=0; j<resources; ++j){
                    if (need[p][j]>work[j]){
                        break;
                    }
                }
                if (j == resources){
                    for (k=0; k<resources; ++k){
                        work[k] += current[p][k];
                    }
                    seq[counter] = p;
                    counter +=1;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0){
            printf("\nThere is a deadlock in the system.");
            return;
        }
    }
    printf("\nSystem is in Safe State. \nSequence : ");
    for (i=0; i<processes; ++i){
        printf("P%d  ", seq[i]);
    }
    printf("\n");
}
 
int main(){

    printf("\nEnter number of Processes: ");
    scanf("%d", &processes);
    printf("Enter number of Resources: ");
    scanf("%d", &resources);
    printf("\nEnter available resources:\n");
    for(i=0; i<resources; i++){ 
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }

    printf("\nEnter Maximum Resources Table:\n");
    for (i=0; i<processes; i++){
        printf("Process %d: ", i);
        for(j = 0; j<resources; j++){
            scanf("%d", &maximum_claim[i][j]);
        }
    }

    printf("\nEnter Allocated Resources Table:\n");
    for (i=0; i<processes; i++){
        printf("Process %d: ", i);
        for(j = 0; j<resources; j++){
          scanf("%d", &current[i][j]);
        }
    }
    isSafe();
    printf("\n");

    return 0;
}