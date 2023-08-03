#include <bits/stdc++.h>
using namespace std;
signed main(){
	int a, b, cnt=0;cin>>a>>b;
	while(a!=1||b!=1){
		if(a>b) a-=b;
		else if(b>a) b-=a;
		else break;
		cnt++;
	}cout<<cnt;
}
