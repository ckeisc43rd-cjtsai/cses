#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<pii> > edge(n+1);
	for(int i=0; i<m; i++){
		int a, b, c;cin>>a>>b>>c;
		edge[a].push_back({b, c});
		edge[b].push_back({a, c});
	}
	priority_queue<pii, vector<pii>, greater<pii>> prim;
	prim.push({0, 1});
	vector<bool> visited(n+1, 0);
	visited[0]=1;
	int cnt=1;
	ll ans=0;
	while(cnt<=n){
		if(prim.empty()){
		cout<<"IMPOSSIBLE";return 0;}
		pii tmp=prim.top();prim.pop();
		
		if(visited[tmp.ss]) continue;
		visited[tmp.ss]=1;
		cnt++;
		//cout<<tmp.ss<<'\n';cout.flush();
		ans+=tmp.ff;
		for(auto x:edge[tmp.ss]){
			if(visited[x.ff]) continue;
			prim.push({x.ss, x.ff});
		}
	}cout<<ans;
}
