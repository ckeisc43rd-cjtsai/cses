#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<int> mac(n);
    for(int i=0; i<n; i++) cin>>mac[i];
    int l=0, r=(int)1e18+7;
    while(l!=r){
        __int128_t mid=(l+r)/2;
        __int128_t cnt=0;
        for(int i=0; i<n; i++) cnt+=mid/mac[i];
        if(cnt>=m) r=mid;
        else l=mid+1;
    }cout<<l;
}

