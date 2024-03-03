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
	int n, q;cin>>n>>q;
	vector<vector<int>> adj(n+1);
	vector<int> val(n+1);
	for(int i=1; i<=n; i++) cin>>val[i];
	vector<int> in(n+1), out(n+1);
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	stack<int> st;
	st.push(1);
	vector<int> dfn;
	vector<bool> vis(n+1, 0);
	vector<int> seg(4*n+7, 0);
	int cnt=0;
	while(!st.empty()){
		int a=st.top();
		if(vis[a]){
			dfn.pb(a);st.pop();out[a]=cnt;cnt++;
		}else{ vis[a]=1;dfn.pb(a);in[a]=cnt;cnt++;}
		for(int x:adj[a]){
			if(vis[x]) continue;
			else{
				st.push(x);
			}
		}
	}
	for(int i=1; i<=n; i++){seg[in[i]+2*n]=val[i];seg[out[i]+2*n]=val[i]*-1;}
	for(int i=2*n-1; i>=0; i--) seg[i]=seg[i*2]+seg[i*2+1];
	for(int i=0; i<q; i++){
		int op;cin>>op;
		if(op==1){
			int a, b;cin>>a>>b;
			int var=b-val[a];
			for(int L=in[a]+2*n; L>0; L/=2){
				seg[L]+=var;
			}
			var=-b+val[a];
			val[a]=b;
			for(int L=out[a]+2*n; L>0; L/=2){
				seg[L]+=var;
			}

		}else if(op==2){
			int a;cin>>a;
			int sum=0;
				for(int L=in[1]+2*n, R=out[a]+2*n; R>L; R/=2, L/=2){
				if(L&1) sum += seg[L++];
				if(R&1) sum += seg[--R];
			}
			cout<<sum<<'\n';
		}
	}
}
