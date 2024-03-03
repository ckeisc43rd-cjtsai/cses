#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAXN 200007

int n;

vector<vector<int>> adj(MAXN);
vector<int> sub(MAXN, 0);
vector<int> dis(MAXN, 0);

void dfs(int root){
	bool chc=false;
	for(int x:adj[root]){
		if(dis[x]) continue;
		chc=true;
		dis[x]=dis[root]+1;
		dfs(x);
	}
	if(!chc) sub[root]=1;
	else{
		for(int x:adj[root])sub[root]+=sub[x];
		sub[root]+=1;
	}
}

int sum=0;

vector<int> diss(MAXN, 0);

void dfs2(int root){
	for(int x:adj[root]){
		if(diss[x]) continue;
		diss[x]=diss[root]-(sub[x])+(n-sub[x]);
		dfs2(x);
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dis[1]=1;
	dfs(1);
	
	for(int i=2; i<=n; i++) sum+=dis[i]-1;
	
	diss[1]=sum;
	dfs2(1);
	for(int i=1; i<=n; i++) cout<<diss[i]<<' ';
}
