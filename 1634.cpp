#include <bits/stdc++.h>
#define pii pair<int, int>
//#define int long long
#define ff first
#define ss second
using namespace std;
vector<int> dp(1000007, INT32_MAX);
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	vector<int> coin(n);
	for(int i=0; i<n; i++){
		cin>>coin[i];
	}
	dp[0]=1;
	for(int i=0; i<n; i++){
		if(coin[i]<=m) dp[coin[i]]=1;
	}
	for(int i=0; i<n; i++){
		for(int j=coin[i]; j<=m; j++){
			if(dp[j-coin[i]]!=INT32_MAX) dp[j]=min(dp[j-coin[i]]+1, dp[j]);
		}
	}
	if(dp[m]!=INT32_MAX)cout<<dp[m];
	else cout<<-1;
}
