#include <iostream>
using namespace std;
#define int long long
long long fastpow(int a,int n){
    if(n==0) return 1;//a^0 = 1
	if(n==1) return a;
    long long half = fastpow(a,n/2);//算出 a^(b/2)
    if(n%2){//n是奇數
        return ((half*half)%1000000007*a)%1000000007;
    } else {
        return (half*half)%1000000007;
    }
}
long long slowpow(int a,int n){
    if(n==0) return 1;//a^0 = 1
	if(n==1) return a;
    long long half = slowpow(a,n/2);//算出 a^(b/2)
    if(n%2){//n是奇數
        return ((half*half)%1000000006*a)%1000000006;
    } else {
        return (half*half)%1000000006;
    }
}
signed main(){
	int s;cin>>s;
	for(int i=0; i<s; i++){
		int b, c, d;cin>>b>>c>>d;
		cout<<fastpow(b, slowpow(c, d))<<'\n';
	}
}
