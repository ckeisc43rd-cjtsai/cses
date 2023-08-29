#include <iostream>
#include <algorithm>
#include <vector>
#define modd 1000000007
using namespace std;

signed main(){
	int n;cin>>n;
	vector<int> r(1000007, 0);
	vector<int> l(1000007, 0);
	r[0]=1;r[1]=1;
	l[0]=1;l[1]=2;
	int onecnt=1;
	int twocnt=2;
	for(int i=2; i<1000001; i++){
		r[i]=onecnt+1;
		onecnt=(r[i]+onecnt)%modd;
		l[i]=onecnt+twocnt+1;
		twocnt=(twocnt+l[i])%modd;
	}
	for(int i=0; i<n; i++){
		int a;cin>>a;
		cout<<l[a]<<'\n';
	}
}
