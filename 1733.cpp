#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
#define modd 1000000007
using namespace std;

int fp(int n, int m){
	if(m==0) return 1;
	if(m==1) return n;
	int tmp=fp(n, m/2);
	if(m%2){
		return tmp*tmp%modd*n%modd;
	}else{
		return tmp*tmp%modd;
	}
}


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	vector<int> aaa(1000007, 1);
	for(int i=1; i<1000007; i++){
		aaa[i]=aaa[i-1]*27%modd;
	}
	string s;cin>>s;
	int sz=s.size();
	vector<int> pre(s.size()+1);
	pre[0]=0;
	for(int i=0; i<s.size(); i++){
		pre[i+1]=(pre[i]*27+s[i]-'a'+1)%modd;
	}
	for(int i=1; i<=s.size(); i++){
		int cnt=sz/i;
		int times = aaa[i*cnt]-1;
		int inv=fp(aaa[i]-1, modd-2);
		int bla=times*inv%modd;
		bla=bla*pre[i]%modd;
		int till=i*cnt;
		int left=sz-till;
		cout<<"cool"<<aaa[till]<<' ';
		int kk=pre[left]*aaa[till]%modd;
		cout<<bla<<' '<<kk<<'\n';
		//cout<<kk+bla<<'\n';
		if((kk+bla)%modd==pre[sz]) cout<<i<<' ';
	}
}
