#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define pii pair<int, int>
#define ff first
//#define int long long
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
	deque<int> dq;
	set<int> st;
	int maxi=0;
	for(int i=0; i<n; i++){
		int a;cin>>a;
		if(st.count(a)){
			while(dq.front()!=a){
				if(dq.size()){st.erase(dq.front());dq.pop_front();}
				else break;
			}if(dq.size())dq.pop_front();
		}dq.push_back(a);
		st.insert(a);
		maxi=max(maxi, (int)dq.size());
	}cout<<maxi;
}
