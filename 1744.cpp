#include <bits/stdc++.h>
using namespace std;
signed main(){
	int a, b;cin>>a>>b;
	vector<vector<int>> dp(a+1, vector<int>(b+1, INT32_MAX-1000));
	for(int i=0; i<=min(a, b); i++) dp[i][i]=0;
	for(int i=0; i<=a; i++){
		//cout<<i;cout.flush();
		for(int j=0; j<=b; j++){
//cout<<j;cout.flush();

			for(int k=1; k<j; k++){
				dp[i][j]=min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
			for(int k=1; k<i; k++){
				dp[i][j]=min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
			}
			//dp[j][i]=dp[i][j];
		}
	}
	cout<<dp[a][b];

}
