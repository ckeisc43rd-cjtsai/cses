#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1, 0);
    for(int i=1; i<n; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> dfs;
    dfs.push(1);
    vis[1]=1;
    int maxi=0, which=1;
    while(!dfs.empty()){
        int tmp=dfs.front();dfs.pop();
        for(int x: adj[tmp]){
            if(!vis[x]){
                vis[x]=vis[tmp]+1;
                if(vis[x]>maxi){
                    maxi=vis[x];which=x;
                }dfs.push(x);
            }
        }
    }//cout<<which;
    dfs.push(which);
    vector<int> vis2(n+1, 0);
    vis2[which]=1;
    maxi=0;
    while(!dfs.empty()){
        int tmp=dfs.front();dfs.pop();
        for(int x: adj[tmp]){
            if(!vis2[x]){
                vis2[x]=vis2[tmp]+1;
                if(vis2[x]>maxi){
                    maxi=vis2[x];which=x;
                }dfs.push(x);
            }
        }
    }cout<<max(maxi-1, (int)0);
}