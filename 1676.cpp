#include <bits/stdc++.h>
using namespace std;
int maxi = INT32_MIN;
int cnt;
vector<int> boss(100007);
vector<int> siz(100007);
int query(int x){
	if(boss[x]==x) return x;
	boss[x]=query(boss[x]);
	siz[x]=siz[boss[x]];
	return boss[x];
}

void modify(int a, int b){
	int fa=query(a);
	int fb=query(b);
	if(fa==fb) return;
	cnt--;
	boss[fa]=fb;
	siz[fb]+=siz[fa];
	if(siz[fb]>maxi) maxi=siz[fb];
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	for(int i=0; i<=n; i++) boss[i]=i;
	for(int i=0; i<=n; i++) siz[i]=1;
	cnt=n;
	for(int i=0; i<m ;i++){
		int a, b;cin>>a>>b;
		modify(a, b);
		cout<<cnt<<' '<<maxi<<'\n';
	}
}
