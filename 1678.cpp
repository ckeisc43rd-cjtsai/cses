#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
vector<int> pa(100007, 0);
vector<vector<int>> adj(100007);
vector<int> ans;
bool u=true;
void solve(int x){
	//for(int i=1; i<6; i++ ) cout<<pa[i]<<' ';
	if(!u) return;
	u=false;
	int ttt=x;
	while(true){
		ans.pb(ttt);
		ttt=pa[ttt];
		if(ttt==x) {ans.pb(x);break;}
	}
}
 
void dfs(int x, int par){
	if(pa[x]) return;
	pa[x]=par;
	//cout<<x<<": ";
	//cout<<adj[x].size();
	for(int tmp:adj[x]){
		//cout<<tmp<<' ';
		if(tmp==par) continue;
		if(pa[tmp]) {pa[tmp]=x;solve(tmp);break;}
		//pa[tmp]=x;
		dfs(tmp, x);
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	//vector<vector<int>> adj(n+1);i
	for(int i=0; i<m; i++){
	 	int a, b;cin>>a>>b;
		adj[a].push_back(b);
		//adj[b].push_back(a);
	}
	//pa[1]=1;
	for(int i=1; i<=n; i++){
		dfs(i, i);
	}
	if(ans.size()==0){
		cout<<"IMPOSSIBLE";
	}else{
		cout<<ans.size()<<'\n';
		for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<' ';
	}
}

