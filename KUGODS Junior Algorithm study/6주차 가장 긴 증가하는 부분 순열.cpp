#include<iostream>
using namespace std;

int dp[1000];
int in[1000];
int main(){
    int N,ans = 1;
    cin>>N;
    
    for(int i=0; i < N ; i++)
        cin>>in[i];
    
    dp[0] = 1;
    for(int i=1; i<N ; i++){
        dp[i] = 1;
        for(int j=i-1; j>=0 ; j--){
            if(in[j]<in[i])
                dp[i] = max(dp[j]+1, dp[i]);
            
        }
        ans = max(dp[i],ans);
        //cout<<dp[i]<<" ";
    }
    
    cout<<ans;
}
