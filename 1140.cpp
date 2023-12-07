#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second

signed main(){
	int n;cin>>n;
	set<pii> st;
	vector<int> li(n+1);
	vector<int> before(n+1);
	int last=0;
	for(int i=1; i<=n; i++){
		int a, b, c;cin>>a>>b>>c;
		li[i]=c;
		st.insert({a, i*-1});
		st.insert({b, i});
	}
	for(auto [a, b]:st){
		if(b<0){
			b*=-1;
			before[b]=last+li[b];
		}else{
			last=max(last, before[b]);
		}
	}cout<<last;
}
