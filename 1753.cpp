#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define modd 712271227

int toint(char e) {
	return (int)(e-'a');
}
int pow2[1000007];
signed main(){
	pow2[0]=1;
	pow2[1]=26;
	for(int i=2; i<1000001; i++){
		pow2[i]=(pow2[i-1]*26)%modd;
	}
	int hash=0;
	int ans=0;
	int cnt=0;
	string a, b;cin>>a>>b;
	int la=a.size(), lb=b.size();//cout<<la<<' '<<lb;
	for(int i=lb-1; i>=0; i--){
		hash=(hash+toint(a[lb-i-1])*pow2[i])%modd;
		ans=(ans+toint(b[lb-i-1])*pow2[i])%modd;
		//cout<<"ans: "<<ans<<'\n';
	}
	//cout<<"ans: "<<ans<<'\n';
	if(hash==ans ) cnt++;
	for(int i=lb; i<la; i++){
		hash=(hash-((toint(a[i-lb])*pow2[lb-1])%modd));
		//cout<<hash<<'\n';
		hash=(hash+modd)%modd;
		hash=(hash*26)%modd;
		hash=(hash+toint(a[i]))%modd;
		if(hash==ans) cnt++;
		//cout<<hash<<'\n';
	}
	cout<<cnt;
}
