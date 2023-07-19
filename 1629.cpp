#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0; i<n; i++){
        int a, b;cin>>a>>b;
        pq.push({b, a});
    }
    int cur=-1, cnt=0;
    while(!pq.empty()){
        pii tmp=pq.top();pq.pop();
        if(tmp.ss>=cur){
            cnt++;
            cur=tmp.ff;
        }
    }cout<<cnt;
}