#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
#define modd 1000000007
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;//cout<<modd;
	if((n*(n+1)/2)%2){
		cout<<0;
		//return 0;
	}else{
		int chc=(n*(n+1))/4;
		vector<int> dp(chc+1, 0);
		for(int i=1; i<=n; i++){
			//dp[i]++;
			for(int j=chc-i; j>=1; j--){
				//modd=1000000007;
				dp[j+i]=((dp[i+j]+dp[j]))%modd;if(dp[j+i]<0) cout<<dp[i+j];
			}dp[i]=(dp[i]+1)%modd;
		}cout<<(dp[chc])*(int)(5e8+4)%1000000007;
	}
}
