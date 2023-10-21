#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

signed main(){
	int n, m, k;cin>>n>>m>>k;
	vector<vector<pii>> adj(n+1);
	vector<vector<pii>> adj2(n+1);
	//vector<int> dis(n+1, 0);
	for(int i=0; i<m; i++){
		int a, b, c;cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj2[b].push_back({a, c});
	}
	priority_queue<pii> pq;
	pq.push({0, n});
	vector<int> dis(n+1, 0);
	vector<int> vis(n+1, 0);
	dis[n]=0;
	while(!pq.empty()){
		pii tmp=pq.top();pq.pop();
		if(vis[tmp.ss]) continue;
		vis[tmp.ss]=1;
		for(pii x:adj2[tmp.ss]){
			if(dis[tmp.ss]+x.ss<dis[x.ff]){
				dis[x.ff]=dis[tmp.ss]+x.ss;
				pq.push({dis[x.ff], x.ff});
			}
		}
	}
	vector<int> dis2(n+1, 0);
	vector<int> vis2(n+1, 0);
	pq.push({0, 1});
	while(!pq.empty()){
		pii tmp=pq.top();pq.pop();
		if(tmp.ss==n  ){ //&& vis2[tmp.ss]==k){
			cout<<dis2[tmp.ss]<<' ';
			if(vis2[tmp.ss]==k)return 0;
		}
		if(vis2[tmp.ss]>k) continue;
		vis2[tmp.ss]++;
		for(pii x:adj[tmp.ss]){
			if(dis2[tmp.ss]+x.ss<dis2[x.ff]){
				dis2[x.ff]=dis2[tmp.ss]+x.ss;
				pq.push({dis2[x.ff], x.ff});
			}
		}

	}
	cout<<-1;
}
