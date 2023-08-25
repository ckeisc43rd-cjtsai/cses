#include <bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    multiset<int> ticket;
	for(int i=0; i<n; i++){
		int a;cin>>a;
		ticket.insert(-a);
	}
	for(int i=0; i<m; i++){
		int a;cin>>a;
		auto it = ticket.lower_bound(-a);
		if(it==ticket.end()){
			cout<<-1<<'\n';
		}else{
			cout<<*it*-1<<'\n';
			ticket.erase(it);
		}
	}
}
