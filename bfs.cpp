#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
int cost[100];
int par[100];
int vis[100];
vector<int>BFS;

void bfs(int source){
    vis[source]=1;
    cost[source]=0;
    par[source]=source;

    queue<int>q;
    q.push(source);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        BFS.push_back(u);
        int v;
        for(int i=0;i<adj[u].size();i++){
            v=adj[u][i];

            if(vis[v]==0){
                vis[v]=1;
                cost[v]=cost[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }



}
int main(){
    int node,edge;
    cin>>node>>edge;

    int u,v;
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int start,dest;
    cin>>start>>dest;
    bfs(start);
    cout<<"Cost of destinantion is "<<cost[dest]<<endl;

    cout<<"DFS list is "<<endl;
    for(int x: BFS){
        cout<<x<<" ";
    }

    vector<int>path;
    int now = dest;
    path.push_back(now);

    while(par[now]!=now){
        now=par[now];
        path.push_back(now);
    }

    cout<<"path is"<<endl;
    for(int x: path){
        cout<<x<<"-->";
    }





}

/*
7 8

1 2
1 4
2 4
2 3
3 5
3 6
4 7
5 6

1 5
*/
