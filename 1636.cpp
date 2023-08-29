#include <iostream>
#include <vector>
#include <algorithm>
#define modd 1000000007
using namespace std;

signed main(){
	int a, b;
	cin>>a>>b;
	vector<int> li(b+1, 0);
	li[0]=1;
	for(int i=0; i<a; i++){
		int t;cin>>t;
		for(int i=0; i+t<=b; i++){
			li[i+t]=(li[i]+li[i+t])%modd;
		}
	}cout<<li[b];
}
