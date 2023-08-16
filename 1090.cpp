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
    int n,m;cin>>n>>m;
    vector<int> chi(n);
    for(int i=0; i<n; i++) cin>>chi[i];
    sort(chi.begin(), chi.end());
    int front=0, end=n-1;
    int cnt=0;
    while(front<=end){
        if(chi[front]+chi[end]<=m){
            //cout<<'f'<<chi[front]<<' '<<chi[end]<<'\n';
            cnt++;
            front++;
            end--;
        }else{
            //cout<<'s'<<chi[end]<<'\n';
            cnt++;
            end--;
        }
    }cout<<cnt;
}
