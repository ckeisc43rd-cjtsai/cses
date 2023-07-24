#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define int long long
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<int> visited(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<int> blocks;
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i]=blocks.size()+1;
            blocks.push_back(i);
            int tmp=visited[i];
            queue<int> bfs;
            bfs.push(i);
            while(!bfs.empty()){
                int tpp=bfs.front();bfs.pop();
                visited[tpp]=tmp;
                for(int x:adj[tpp]){
                    if(!visited[x]){
                        visited[x]=tmp;
                        bfs.push(x);
                    }
                }
            }
        }
    }
    cout<<blocks.size()-1<<'\n';
    for(int i=1; i<blocks.size(); i++){
        cout<<blocks[0]<<' '<<blocks[i]<<'\n';
    }
}