#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main(){
    int n, k;cin>>n>>k;
    vector<pii> li(n);
    for(int i=0; i<n; i++){
        int a, b;cin>>a>>b;
        li[i]={b, a};
    }
    sort(li.begin(), li.end());
    int cnt=0;
    multiset<int> mst;
    for(int i=0; i<k; i++) mst.insert(0); 
    for(int i=0; i<n; i++){
        auto but=mst.lower_bound(li[i].ss*-1);
        if(but==mst.end()) continue;
        mst.erase(but);
        mst.insert(li[i].ff*-1);
        cnt++;
    }cout<<cnt;
}