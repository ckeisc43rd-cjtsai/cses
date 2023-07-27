#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
#define MAXN 500
#define modd (int)1e9+7
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<priority_queue<pii>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        adj[a].push({c, b});
        adj[b].push({c, a});
    }
}