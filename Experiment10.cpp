#include <bits/stdc++.h>
using namespace std;
int main(){
    int frame_size=3;
    int page_faults=0;
    vector<int> ref_string={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    queue<int> q;
    unordered_set<int> check;
    for(auto it:ref_string){
        if(check.find(it)==check.end()){
            if(q.size()>=frame_size){
                check.erase(q.front());
                q.pop();
            }
            q.push(it);
            check.insert(it);
            page_faults++;
        }
    }
    cout<<"Total Number of page faults: "<<page_faults<<"\n";
}