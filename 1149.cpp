#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define modd 1000000007

int fp(int x, int p){
	if(p==0) return 1;
	if(p==1) return x;
	int tmp=fp(x, p/2);
	if(p%2return tmp*tmp*x;
	return tmp*tmp;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string a;cin>>a;
	vector<int> cnt(30, 0);
	int inv=fp(2, modd-2);
	int ans=1;
	for(int i=0; i<(int)a.size(); i++){
		ans*=2;
		ans%=modd;
		ans-=cnt[a[i]-'a'];
		cnt[a[i]-'a']+=(ans*inv);
		cnt[a[i]-'a']%=modd;
	}cout<<ans-1;
}

