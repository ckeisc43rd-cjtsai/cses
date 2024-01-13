#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, q;cin>>n>>q;
	multiset<int> st;
	vector<int> sal(n);
	for(int i=0; i<n; i++){
		int a;cin>>a;
		st.insert(a);
		sal[i]=a;
	}
	for(int i=0; i<q; i++){
		char det;cin>>det;
		if(det=='?'){
			int a, b;cin>>a>>b;
			auto pa=st.lower_bound(a);
			auto pb=st.upper_bound(b);
			cout<<b-a<<'\n';
		}else{
			int k, x;cin>>k>>x;
			int ori=sal[k];
			sal[k]=x;
			st.erase(st.find(ori));
			st.insert(x);
		}
	}
}
