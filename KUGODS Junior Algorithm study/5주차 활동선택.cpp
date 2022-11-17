#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> v;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
    
}
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    
    sort(v.begin(), v.end(), compare);

    int ans = 0;
    int end = 0;
    for(int i=0; i<N; i++){
        if(v[i].first >= end){
            end = v[i].second;
            ans ++;
        }
    }
    cout<<ans;
}
