#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long 

signed main(){
	int n;cin>>n;
	for(int i=1; i<=n; i++){
		int tmp=(i*i)*(i*i-1)/2;
		cout<<tmp-4*(i-1)*(i-2)<<'\n';
	}
}
