#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> li(1000007, -1);

int dp(int e){
//	cout<<e<<'\n';
	if(e<10) return 1;
	//priority_queue<int, vector<int>, less<int> > ans;
	int s=e;int mini=INT32_MAX;
	while(s>0){
		int t=s%10;
		s/=10;
		if(t==0) continue;
		int tmp;
		if(li[e-t]==-1) tmp=dp(e-t);
		else tmp=li[e-t];
		mini=min(mini, tmp+1);
	}
	return li[e]=mini;
}

signed main(){
	int n;cin>>n;
	for(int i=0; i<10; i++) li[i]=1;
	dp(n);
	cout<<li[n];
}
