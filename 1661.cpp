#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, k;cin>>n>>k;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	int pre=0;
	map<int, int> bla;
	bla[0]=1;
	int cnt=0;
	for(int i=0; i<n; i++){
		pre+=a[i];
		cnt+=bla[pre-k];
		bla[pre]++;
	}cout<<cnt;
}
