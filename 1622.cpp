#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

signed main(){
	string a;cin>>a;
	int da=a.size();
	sort(a.begin(), a.end());
	vector<string> ans;
	string x=a;
	ans.push_back(a);
	next_permutation(x.begin(), x.end());
	while(x!=a){
		ans.push_back(x);
		next_permutation(x.begin(), x.end());
		//ans.push_back(x);
	}
	cout<<ans.size()<<'\n';
	for(string x:ans) cout<<x<<'\n';
}
