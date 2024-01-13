#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<vector<int>> tel(200007);
vector<vector<int>> ans(23, vector<int>(200007, -1));
vector<vector<int>> adj(200007);
vector<int> dep(200007);
int pow2[40];
void dfs(int x, int p){
	dep[x]=dep[p]+1;
	for(int z:adj[x]){
		if(z==p) continue;
		dfs(z, x);
	}
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	pow2[0]=1;
	for(int i=1; i<40; i++) pow2[i]=pow2[i-1]*2;
	cin>>n>>q;
	//ans[0][1]=1;
	for(int i=2; i<=n; i++){cin>>ans[0][i];adj[ans[0][i]].push_back(i);}
	dfs(1, 0);
	dep[1]=0;
	for(int i=1; i<23; i++){
		for(int j=1; j<=n; j++){
			ans[i][j]=ans[i-1][ans[i-1][j]];
		}
	}
	for(int i=0; i<q; i++){
		int x,y;cin>>x>>y;
		if(dep[x]>dep[y]) swap(x, y);
		int mi=dep[y]-dep[x];
		while(mi>1){
			int dd=__lg(mi);
			y=ans[dd][y];
			mi-=dd;
		}
		for(int j=20; j; j--){
			if(ans[j][x]!=ans[j][y]){
				x=ans[j][x];
				y=ans[j][y];
			}
		}cout<<ans[0][x]<<'\n';
	}
}

