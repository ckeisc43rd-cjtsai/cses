#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	vector<int> li(n+1);
	for(int i=1; i<=n; i++) cin>>li[i];
	vector<int> dp(n+1);
	sort(li.begin(), li.end());
	dp[0]=1;
	for(int i=1; i<=n; i++){
		if(dp[i-1]<li[i]) return cout<<dp[i-1], 0;
		dp[i]=dp[i-1]+li[i];
		cout<<dp[i]<<'\n';
	}
	cout<<dp[n];
}
