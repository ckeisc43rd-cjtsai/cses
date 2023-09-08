#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	vector<int> li(n);
	vector<int> ans(101000, 0);
	ans[0]=1;
	for(int i=0; i<n; i++) cin>>li[i];
	for(int i=0;i<n; i++){
		for(int j=100000; j>=0; j--){
			if(ans[j]==1) ans[j+li[i]]=1;
		}
	}
	int cnt=0;
	for(int i=1; i<100001; i++) if(ans[i]) cnt++;
	cout<<cnt<<'\n';
	for(int i=1; i<100001; i++){
		if(ans[i]) cout<<i<<' ';
	}
}
