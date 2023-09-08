#include <iostream>
#include <algorithm>
#include <vector>
#define pss pair<string, string>
using namespace std;

vector<string> ans;

vector<string> solve(int t){
	vector<string> ret;
	if(t==1){
		vector<string> rrr(2);
		rrr[0]="0";rrr[1]="1";
		return rrr;
	}else{
		vector<string> li=solve(t-1);
	//	vector<string> ret;
		for(int i=0; i<li.size(); i++){
			string alpha, beta;
			if(i%2){
				alpha="0";beta="1";
			}else{
				alpha="1";beta="0";
			}
			ret.push_back(alpha+li[i]);
			ret.push_back(beta+li[i]);
		}
	}return ret;
}





signed main(){
	int n;cin>>n;
	vector<string> sss=solve(n);
	for(string x:sss) cout<<x<<'\n';
}
