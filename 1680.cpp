#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
//#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 500
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> dfs;
    dfs.push(1);
    vector<int> dis(n+1, 0);
    vector<int> pa(n+1);
    while(!dfs.empty()){
        int tmp=dfs.front();dfs.pop();
        for(int x:adj[tmp]){
            //if(x==tmp) continue;
            if(dis[tmp]+1>dis[x]){
                pa[x]=tmp;
                dis[x]=dis[tmp]+1;
                dfs.push(x);
            }
        }
    }
    int maxi=dis[n], which=n;
    if(maxi){
        cout<<maxi+1<<'\n';
        vector<int> ans;
        while(which!=1){
            ans.push_back(which);
            which=pa[which];
        }cout<<1<<' ';
        for(int i=ans.size()-1; i>=0; i--)cout<<ans[i]<<' ';
    }else cout<<"IMPOSSIBLE";
}