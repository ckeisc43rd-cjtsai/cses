#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<m; i++){
		int a;cin>>a;
		pq.push(a);
	}
	int ans=0;
	while(pq.size()>1){
		int a=pq.top();pq.pop();
		int b=pq.top();pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}cout<<ans;

}
