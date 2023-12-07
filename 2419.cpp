#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
int lb(int x){return x&(-x);}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	vector<int> xo(n, 0);
	int u=n-1, d=1;
	for(int i=1; i<n; i++){
		xo[i]=xo[i-1]+lb(u)-lb(d);
		u--;
		d++;
	}
	int ans=0;
	for(int i=0; i<n; i++){
		int a;cin>>a;
		if(!xo[i])ans^=a;
	}
	cout<<ans;
}
