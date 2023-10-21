#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n,k;cin>>n>>k;
	vector<int> li(n);
	for(int i=0; i<n; i++)cin>>li[i];
	int f=1, s=0, ans=0;
	int cnt=li[0];
	while(s<n){
		if(cnt>k){
			cnt-=li[s];
			s++;
		}else if(cnt<k){
			if(f>n) break;
			cnt+=li[f];
			f++;
		}else{
			ans++;
			cnt-=li[s];
			s++;
		}
	}cout<<ans;
}
