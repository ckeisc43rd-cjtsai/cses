#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define maxn 262145
int n, L;
vector<int> st(2*maxn);

void update(int t, int x){
	st[L+t]-=x;
	int d=st[L+t];
	for(int i=(L+t)>>1; i; i>>=1) st[i]=max(st[i*2], st[(i*2)+1]);
}

int query(int t){
	if(st[1]<t) return 0;
	int i=1;
	for(; i<L;){
		if(st[2*i]>=t) i=2*i;
		else i=2*i+1;
	}
	return i;
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int  m;cin>>n>>m;
	L=__lg(n-1);
	L=262144;
	for(int i=L; i<L+n; i++) cin>>st[i];
	for(int i=L-1; i; i--) st[i]=max(st[2*i], st[2*i+1]);
	for(int i=0; i<m; i++){
		int s;cin>>s;
		int qs=query(s);
		cout<<((qs)?qs-L+1:0)<<' ';
		if(qs!=0)update(qs-L, s);
		//cout<<'\n';
		//for(int x=0; x<20; x++) cout<<st[x]<<' ';
		//cout<<'\n';
	}
}
