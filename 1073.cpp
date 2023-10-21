#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n;cin>>n;
	multiset<int> ans;
	for(int i=0; i<n; i++){
		int a;cin>>a;
		//if(ans.empty()) ans.insert(a);
		auto buf=ans.upper_bound(a);
		if(buf==ans.end()) ans.insert(a);
		else {ans.erase(buf);ans.insert(a);}
	}cout<<ans.size();
}
