#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> par(n+1, 0);
    vector<int> dep(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> bfs;
    dep[1]=1;
    bfs.push(1);
    while(!bfs.empty()){
        int tmp=bfs.front();bfs.pop();
        for(int x:adj[tmp]){
            if(!par[x]){
                par[x]=tmp;
                dep[x]=dep[tmp]+1;
                bfs.push(x);
            }
        }
    }
    if(dep[n]==0)cout<<"IMPOSSIBLE";
    else{
        cout<<dep[n]<<'\n';
        vector<int> path;
        path.push_back(n);
        int tmp=n;
        while(tmp!=1){
            tmp=par[tmp];
            path.push_back(tmp);
        }
        for(int i=path.size()-1; i>=0; i--) cout<<path[i]<<' ';
    }
}