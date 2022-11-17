#include<iostream>
#include<vector>
using namespace  std;
vector<long long> dist, cost;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N-1;i++){
        long long tmp;
        cin>>tmp;
        dist.push_back(tmp);
    }
    
    for(int i=0;i<N;i++){
        long long tmp;
        cin>>tmp;
        cost.push_back(tmp);
    }
    long long ans = 0;
    long long min_cost = cost[0];
    for(int i=0; i<N-1; i++){
        if(min_cost > cost[i])
            min_cost = cost[i];
        ans+=min_cost*dist[i];
    }
    cout<<ans;
    
    
}
