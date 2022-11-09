#include<iostream>
using namespace std;
int n,m;
int map[102][102];
int visited[102][102];
int dir[4][2] = {{0,1},{1,0}, {-1,0}, {0,-1}};

void check(int a, int b){
    int cnt = 0;
    for(int i=0; i<4;i++){
        int na = a+dir[i][0], nb = b+dir[i][1];
        if(map[na][nb] == 3)
            cnt++;
    }
    if(cnt>=2)
        map[a][b] = 2;
}


void dfs(int a, int b){
    map[a][b] = 3;
    for(int i=0; i<4;i++){
        int na = a+dir[i][0], nb = b+dir[i][1];
        if(na<=0 || nb <= 0 || na>n || nb>m || map[na][nb] == 1 || map[na][nb] == 3 )
            continue;
        dfs(na,nb);
        
    }
}


int main(){
    cin>>n>>m;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=m;j++)
            cin>>map[i][j];

    dfs(1,1);

    int day = 0;
    while(1){
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j]==1)
                    check(i,j);
            }
        }
        
        //--------------------------------------
//        cout<<"--------"<< day<<"--------\n";
//        for(int i=1; i<=n;i++){
//            for(int j=1; j<=m;j++){
//                if(map[i][j] == 3)
//                    cout<<0<<" ";
//                else
//                cout<<map[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl<<endl;
        //--------------------------------------
        int cnt = 0;
        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j] == 1)
                    cnt+=1;
            }
        }

        for(int i=1; i<=n;i++){
            for(int j=1; j<=m;j++){
                if(map[i][j]==2){
                    map[i][j] = 3;
                    dfs(i,j);
                }
                visited[i][j] = 0;
            }
        }
        
        day++;
        if(cnt==0)
            break;
    }
    cout<<day<<endl;
        
}
