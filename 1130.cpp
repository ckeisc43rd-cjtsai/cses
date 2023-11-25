#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

vector<vector<int>> adj(200007);
vector<bool> vis(200007, 0);
int ans=0;

void dfs(int x, int p){
	for(int z:adj[x]){
			if(z==p) continue;
		dfs(z, x);
		if(!vis[z]&&!vis[x]){
			vis[z]=1;
			vis[x]=1;
			ans++;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	cout<<ans;
}
