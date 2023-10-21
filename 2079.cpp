#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(200007);
vector<int> si(200007, 1);
int root=1;
int dfs(int x, int pa){
	for(int d:adj[x]){
		if(d==pa) continue;
		si[x]+=dfs(d, x);
	}
	return si[x];
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
	bool chc=false;int cnt=0;
	for(int i=1; i<=n; i++) cout<<si[i]<<' ';
	return 0;
	while(true){
		cnt++;
		//cout<<tmp<<' ';cout.flush();
		//if(chc) break;
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
		if(!chc||(cnt>n)){
			cout<<tmp;
			return 0;
		}
	}
}


/*
1
4    7
     2
	 10
	 9
	 8
	 3
	 6
	 5
10 7 3 1 1 2 8 4 5 6 
 */
