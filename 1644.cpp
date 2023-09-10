#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define int long long
signed main(){
	int n, a, b;cin>>n>>a>>b;
	vector<int> li(n+2);
	li[0]=0;
	for(int i=1; i<=n; i++){
		int c;cin>>c;
		li[i]=c+li[i-1];
	}
	multiset<int> st;
	int ans=INT64_MIN;
	for(int i=a; i<=n; i++){
		st.insert(li[i-a]);
		if(i>b) st.erase(st.find(li[i-b-1]));
		ans=max(ans, li[i]-*st.begin());

	}cout<<ans;
}
