#include<iostream>
#include<queue>
#include<string>
 
using namespace std;

queue<long long> q[21];
 
int main() {
    long long N,K,ans=0;
    cin>>N>>K;
    for(long long i=1;i<=N;i++){
        string name;
        cin>>name;
        q[name.length()].push(i);
        
        while(i-q[name.length()].front()>K){
            q[name.length()].pop();
        }
        ans+=q[name.length()].size()-1;
    }
    cout<<ans;

}

