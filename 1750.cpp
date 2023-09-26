#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q;
vector<vector<int>> tel(200007);
vector<vector<int>> ans(35, vector<int>(200007, -1));
vector<int> dep(200007);
int pow2[40];
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	pow2[0]=1;
	for(int i=1; i<40; i++) pow2[i]=pow2[i-1]*2;
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>ans[0][i];
	for(int i=1; i<35; i++){
		for(int j=1; j<=n; j++){
			ans[i][j]=ans[i-1][ans[i-1][j]];
		}
	}
	for(int i=0; i<q; i++){
		int x,k;cin>>x>>k;
		while(k>0){
			int tmp=__lg(k);
			x=ans[tmp][x];
			k-=(pow2[tmp]);
		}
		cout<<x<<'\n';
	}
}
