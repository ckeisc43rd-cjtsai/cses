#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	vector<vector<int>> adj(n);
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
}
