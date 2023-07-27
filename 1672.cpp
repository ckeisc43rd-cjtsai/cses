#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
#define MAXN 500
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m, s;cin>>n>>m>>s;
    vector< vector<int> > d(n+1, vector<int>(n+1, (int)1000*INT32_MAX));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i==j) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    while(s--){
        int a, b;cin>>a>>b;
        if(d[a][b]>(int)500*INT32_MAX)cout<<-1<<'\n';
        else cout<<d[a][b]<<'\n';
    }
}