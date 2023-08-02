#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	const int MAXN = 3005;
	int n;
    cin >> n;int cnt=0;
	int dp[n][n];
	int s[n];
	for(int i = 0; i < n; ++i) {
        cin >> s[i];cnt+=s[i];
        dp[i][i] = s[i];
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; i+j < n; ++j) {
            dp[j][i+j] = max(s[j] - dp[j+1][i+j], s[i+j] - dp[j][i+j-1]);
        }
    }
    cout << (cnt-dp[0][n-1])/2+dp[0][n-1] << '\n';
}

