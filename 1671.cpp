#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
#define int unsigned long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        adj[a].push_back({c, b});
        //adj[b].push_back({c, a});
    }priority_queue<pii, vector<pii>, greater<pii>> ijk;
    vector<int> dis(n+1, INT64_MAX);
    dis[1]=0;
    vector<bool> vis(n+1, 0);
    ijk.push({0, 1});
    while(!ijk.empty()){
        pii tmp=ijk.top();ijk.pop();
        if(vis[tmp.ss]) continue;
        vis[tmp.ss]=1;
        for(pii x:adj[tmp.ss]){
            //cout<<"bla"<<x.ss<<'\n';
            if(dis[tmp.ss]+x.ff<dis[x.ss]){
                dis[x.ss]=dis[tmp.ss]+x.ff;
                ijk.push({dis[x.ss], x.ss});
            }
        }
    }for(int x=1; x<=n; x++) cout<<dis[x]<<' ';
    return 0;
}