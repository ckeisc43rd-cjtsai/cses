#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	priority_queue<pii> in;
	priority_queue<pii> out;
	for(int i=0; i<n; i++){
		int a, b;cin>>a>>b;
		in.push({a, b});
	}
	out.push(in.top());in.pop();
	int ans=1;
	while(true){
		if(out.empty()){
			if(in.empty()){
				break;
			}else{
				out.push(in.top());
				in.pop();
			}
		}else{
			if(in.top().ff<out.top().ff){
				out.push(in.top());
				in.pop();
				ans=max(ans, out.size());
			}else{
				out.pop();
			}
		}
	}
	cout<<ans;
}
