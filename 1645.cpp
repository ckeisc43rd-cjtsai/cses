#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	vector<int> li(n+10);
	for(int i=0; i<n; i++) cin>>li[i];
	vector<pii> ans;
	for(int i=0; i<n; i++){//cout<<i;
		if(ans.empty()){
			cout<<0<<' ';
			ans.push_back({li[i], i});
		}else{
			while(ans.back().ff>=li[i]&&!(ans.empty())){
                ans.pop_back();
			}//return 0;
			if(ans.empty()){
				cout<<0<<' ';
			}else{
				cout<<ans.back().ss+1<<' ';
			}
			ans.push_back({li[i], i});
		}
	}
}
