#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool visited[9];
vector<int> graph[9];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

void dfs_st(int start)
{
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while(!st.empty())
    {
        int x = st.top();
        st.pop();
        cout << x << " ";
        //for (int i = graph[x].size()-1; i >=0 ; i--)
        for (int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if (!visited[y]){
                st.push(y);
                visited[y] = true;
            }
               
        }
    }
}

void dfs_re(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++)
    {
        int y = graph[x][i];
        if (!visited[y])
            dfs_re(y);
    }
}

int main(void)
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(1);
    graph[2].push_back(5);
    graph[2].push_back(6);
    
    graph[3].push_back(1);
    graph[3].push_back(7);

    graph[4].push_back(1);
    graph[4].push_back(7);

    graph[5].push_back(2);
    graph[5].push_back(6);

    graph[6].push_back(2);
    graph[6].push_back(5);

    graph[7].push_back(2);
    graph[7].push_back(8);
    graph[7].push_back(4);
    

    graph[8].push_back(7);
    
    dfs_st(1);
    cout<<endl;
    memset(visited, 0, 9);
    dfs_re(1);
    cout<<endl;
    memset(visited, 0, 9);
    bfs(1);
}
