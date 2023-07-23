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
    int n;cin>>n;
    int ans=0, maxi=INT32_MIN;
    while(n--){
        int a;cin>>a;
        maxi=max(maxi, ans+a);
        ans=max(ans+a, (int)0);
    }cout<<maxi;
}