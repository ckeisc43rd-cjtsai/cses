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
	int n;cin>>n;
	int aa=1;
	int s=1;
	int ans=0;
	while(n>=(s*2)-1){
		if(n>=s){
			ans+=s*aa;
		}
		s*=2;
		aa++;
	}
	ans+=(n-s+1)*aa;
	cout<<ans;

}
