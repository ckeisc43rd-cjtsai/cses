#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define int long long
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<int> li(n);
    for(int i=0; i<n; i++) cin>>li[i];
    sort(li.begin(), li.end());li.push_back(0);
    int fast=1, slow=0;
    int tmp=li[0], cnt=0;
    while(fast<=n){
        if(tmp>m){
            tmp-=li[slow];
            slow++;
        }else if(tmp<m){
            tmp+=li[fast];
            fast++;
        }else{
            cnt++;cout<<fast<<' '<<slow<<'\n';
            tmp+=li[fast];tmp-=li[slow];
            fast++;slow++;
        }
    }cout<<cnt;
}