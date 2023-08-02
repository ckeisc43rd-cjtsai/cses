#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

signed main(){
	int n, k;cin>>n>>k;
	vector<int> price(n+1);
	vector<int> page(n+1);
	vector<int> dp(k+1, 0);
	for(int i=1; i<=n; i++)cin>>price[i];
	for(int i=1; i<=n; i++)cin>>page[i];
	for(int i=0; i<=n; i++){
		for(int j=k; j-price[i]>=0; j--){
			dp[j]=max(dp[j-price[i]]+page[i],dp[j]); 
		}
	}
	int maxi=0;
	for(int i=0; i<=k; i++) if(dp[i]>maxi) maxi=dp[i];
	cout<<maxi;
}
