#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	vector<int> li(n+2, 0);
	vector<int> val(n+2, 0);
	li[n+1]=INT32_MAX;
	for(int i=1; i<=n; i++){
		int t;cin>>t;
		li[t]=i;
		val[i]=t;
	}

	int cnt=1;
	for(int i=1; i<n-1; i++){
		if(li[i]>li[i+1]){
			cnt++;
		}
	}cout<<cnt<<'\n';
	for(int i=0; i<m; i++){
		int a, b;cin>>a>>b;
		int da=val[a], db=val[b];
		int tmp=0;
		if(li[da-1]>a){
			tmp++;
		}
		if(li[da+1]<a){
			tmp++;
		}
		if(li[db-1]>b){
			tmp++;
		}
		if(li[db+1]<b){
			tmp++;
		}
		int vvv=val[a];
		int eee=val[b];
		val[a]=eee;
		val[b]=vvv;
		li[vvv]=b;
		li[eee]=a;
		int tpp=0;
		if(li[da-1]>b){
			tpp++;
		}
		if(li[da+1]<b){
			tpp++;
		}
		if(li[db-1]>a){
			tpp++;
		}
		if(li[db+1]<a){
			tpp++;
		}
		cnt=cnt-tmp+tpp;
		cout<<cnt<<'\n';
	}
}
