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
    vector<int> team(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!team[i]){
            team[i]=1;
            queue<int> dfs;
            dfs.push(i);
            while(!dfs.empty()){
                int tmp=dfs.front();dfs.pop();
                for(int x:adj[tmp]){
                    if(team[x]==team[tmp]){
                        cout<<"IMPOSSIBLE";return 0;
                    }
                    if(!team[x]){
                        team[x]=team[tmp]^3;
                        dfs.push(x);
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<team[i]<<' ';
}