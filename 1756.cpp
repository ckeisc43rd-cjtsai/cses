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
	int n, m;cin>>n>>m;
	//vector<vector<int>> adj(n+1, vector<int>(n+1));
	for(int i=0; i<m; i++) {
		int a, b;cin>>a>>b;
		cout<<min(a, b)<<' '<<max(a, b)<<'\n';
	}
}
