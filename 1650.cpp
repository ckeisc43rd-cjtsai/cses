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
    vector<int> val(n), xxx(n+1);
    for(int i=0; i<n; i++) cin>>val[i];
    xxx[0]=0;
    for(int i=1; i<=n; i++){
        xxx[i]=val[i-1]^xxx[i-1];
    }
    while(m--){
        int a, b;cin>>a>>b;
        cout<<(xxx[b]^xxx[a-1])<<'\n';
    }
}