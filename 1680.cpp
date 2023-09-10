#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;


signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	vector<vector<int> > adj(n+1);
	vector<int> adj2(n+1, 0);
    vector<int> pre(n+1);
	for(int i=0; i<m; i++){
		int a, b;cin>>a>>b;
		adj[a].push_back(b);
		adj2[b]++;
	}
	vector<int> dis(n+1, INT32_MAX);
    vector<int> vis(n+1, 0);
	dis[1]=0;
	queue<int> ijk;
    for(int i=1; i<=n; i++){
        if(adj2[i]==0) ijk.push(i);
    }
    while(!ijk.empty()){
        int tmp=ijk.front();ijk.pop();
        for(int x:adj[tmp]){
            if(dis[tmp]-1<dis[x]){
                pre[x]=tmp;
                dis[x]=dis[tmp]-1;
                
            }
            adj2[x]--;
            if(adj2[x]==0&&!vis[x]){ijk.push(x);vis[x]=1;}
        }
    }
    vector<int> ans;
    if(dis[n]>n){
        cout<<"IMPOSSIBLE";
    }else{
        int cur=n;
        while(cur!=1){
            ans.push_back(cur);
            cur=pre[cur];
        }
        cout<<ans.size()+1<<'\n';
        cout<<1<<' ';
        for(int i=ans.size()-1; i>=0; i--){
            cout<<ans[i]<<' ';
        }
    }
}
