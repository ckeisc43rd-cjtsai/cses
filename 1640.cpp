#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<pii> li(n);
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        li[i]={tmp, i+1};
    }
    sort(li.begin(), li.end());
    int l=0, r=n-1;
    while(r>l){
        if(li[l].ff+li[r].ff>m) r--;
        else if(li[l].ff+li[r].ff<m) l++;
        else{
            cout<<min(li[l].ss, li[r].ss)<<' '<<max(li[l].ss, li[r].ss);
            return 0;
        }
    }cout<<"IMPOSSIBLE";
}