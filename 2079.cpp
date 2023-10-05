#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(200007);
vector<int> si(200007, 0);
int root=1;
int dfs(int x, int pa){
	for(int d:adj[x]){
		if(d==pa) continue;
		si[x]+=dfs(d, x);
	}
	return si[x]+1;
}

signed main(){
	int n;cin>>n;
		for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	int tmp=1;
	bool chc=false;
	while(true){
		//cout<<tmp<<' ';
		if(chc) break;
		chc=false;
		int tpp=n-1;
		for(int x:adj[tmp]){
			//cout<<si[x];
			if(si[x]>n/2){
				tmp=x;
				chc=true;
				break;
			}tpp-=si[x];
		}
		if(chc){
			cout<<tmp;
			return 0;
		}
	}
}
