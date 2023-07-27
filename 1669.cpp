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
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int> > adj(n+1);
    vector<int> pa(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> dfs;
    dfs.push(1);
    pa[1]=-1;
    int end=0;
    int balala;
    while(!dfs.empty()){
        int tmp=dfs.front();dfs.pop();
        for(int x:adj[tmp]){
            if(x==pa[tmp]) continue;
            if(pa[x]){
                pa[x]=tmp;
                end=tmp;
                goto sus;
            }else{
                pa[x]=tmp;
                dfs.push(x);
            }
        }
    }
    if(!end){
        cout<<"IMPOSSIBLE"; 
        return 0;
    }
    sus:
    int tmp=pa[end];
    //cout<<balala;
    vector<int> ans;
    while(tmp!=end){
        //cout<<tmp;
        ans.push_back(tmp);
        tmp=pa[tmp];
    }//ans.push_back(balala);
    cout<<ans.size()<<'\n';
    for(int x:ans) cout<<x<<' ';
}