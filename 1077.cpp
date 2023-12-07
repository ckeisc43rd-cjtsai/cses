#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, k;cin>>n>>k;
	vector<int> num(n);
	for(int i=0; i<n; i++) cin>>num[i];
	vector<int> dd(k);
	for(int i=0; i<k; i++){
		dd[i]=num[i];
	}
	int bg=(k+1)/2;
	int sm=(k/2);
	sort(dd.begin(), dd.end());
	set<int> sms, bgs;
	if(k%2){
		int cnt=0;
		int mid=k/2+1;
		for(int i=0; i<mid-1; i++){
			sms.insert(dd[i]);
			cnt+=dd[i];
		}for(int i=mid; i<k; i++){
			bgs.insert(dd[i]);
			cnt+=dd[i];
		}
		for(int i=k; i<n; i++){

		}
	}else{

	}
	
}
