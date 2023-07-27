#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 500
#define modd (int)1e9+7
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> ind(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        ind[b]++;
    }
    vector<bool> vis(n+1, 0);
    queue<int> bfs;
    vector<int> ways(n+1, 0);
    //bfs.push(1);
    for(int i=1; i<=n; i++){
        if(ind[i]==0) bfs.push(i);
    }
    ways[1]=1;
    while(!bfs.empty()){
        int tmp=bfs.front();bfs.pop();
        //cout<<"lala"<<tmp<<' '<<ways[tmp]<<"lala\n";
        if(vis[tmp]) continue;
        vis[tmp]=1;
        for(int x:adj[tmp]){
            ways[x]=(ways[x]+ways[tmp]);//%modd;
            if(ways[x]>0)ways[x]%=modd;
            ind[x]--;
            if(ind[x]==0)bfs.push(x);
        }
    }cout<<ways[n];
}