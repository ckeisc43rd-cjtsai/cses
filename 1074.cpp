#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> pq(n);
    for(int i=0; i<n; i++){
        cin>>pq[i];
    }
    sort(pq.begin(), pq.end());
    int nn=pq[n/2];
    int ans=0;
    for(int i=0; i<n; i++) ans+=(abs(pq[i]-nn));
    cout<<ans;

}