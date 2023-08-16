#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;
int modd=712271227;

int toint(char e){
	return e-'a';
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int pow2[1000007];
	pow2[0]=1;pow2[1]=26;
	for(int i=2; i<1000001; i++) pow2[i]=(pow2[i-1]*26)%modd;
	string a;cin>>a;
	int la=a.size();
	int pre=toint(a[0]);
	int suf=toint(a[la-1]);
	int cnt=0;
	if(pre==suf) cout<<1<<' ';
	for(int i=1; i<la-1; i++){
		pre=(pre+toint(a[i])*pow2[i])%modd;
		suf=suf*26%modd;
		suf=(suf+toint(a[la-i-1]))%modd;
		if(pre==suf) cout<<i+1<<' ';
	}
}
