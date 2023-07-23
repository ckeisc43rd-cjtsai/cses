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
    if(adj[1].size()==1){
        queue<int> dfs;
        dfs.push(1);
        int maxi=1;
        while(!dfs.empty()){
            int tmp=dfs.front();dfs.pop();
            for(int x:adj[tmp]){
                if(!vis[x]){
                    vis[x]=vis[tmp]+1;
                    if(vis[x]>maxi) maxi=vis[x];
                    dfs.push(x);
                }
            }
        }cout<<maxi;
        return 0;
    }
    vis[1]=1;
    vector<int> ans;
    for(int x:adj[1]){
        queue<int> dfs;
        dfs.push(x);
        while(!dfs.empty()){
            int tmp=dfs.front();dfs.pop();
            bool cool=true;
            for(int x:adj[tmp]){
                if(!vis[x]){
                    cool=false;
                    vis[x]=vis[tmp]+1;
                    dfs.push(x);
                }if(cool) ans.push_back(vis[x]);
            }
        }
    }sort(ans.begin(), ans.end());
    cout<<ans[ans.size()-1]+ans[ans.size()-2]-1;
}