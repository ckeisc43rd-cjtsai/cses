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
vector<int> dis(MAXN, 0);
vector<int> dis2(MAXN, 0);
vector<vector<int>> adj(MAXN);
int det=0;
int dfs(int root){
	stack<int> st;
	st.push(root);
	for(int i=0; i<=n; i++) dis[i]=0;
	dis[root]=1;
	while(!st.empty()){
		int x=st.top();st.pop();
		for(int a:adj[x]){
			if(dis[a]) continue;
			dis[a]=dis[x]+1;
			st.push(a);
		}
	}
	int maxi=0, ind;
	for(int i=1; i<=n; i++){
		if(dis[i]>maxi){
			maxi=dis[i];
			ind=i;
		}
	}
	if(det==1){
		for(int i=1; i<=n; i++) dis2[i]=dis[i];
	}
	return ind;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int far=dfs(1);
	det=1;
	int far2=dfs(far);
	det=0;
	dfs(far2);
	for(int i=1; i<=n; i++) cout<<max(dis[i], dis2[i])-1<<' ';
}
