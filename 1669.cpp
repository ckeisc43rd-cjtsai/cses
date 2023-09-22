#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve(int x){
	i
}

void dfs(int x, int par){
	if(pa[x]==par) return;
	if(pa[x]) solve(x);

}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	vector<vector<int>> adj(n+1);
	for(int i=0; i<m; i++){
	 	int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> pa(n+1, -1);
	pa[1]=1;
	stack<int> dfs;
	dfs(1);
}
