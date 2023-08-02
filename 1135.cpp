#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 200007
using namespace std;
int n;
int dep[maxn];
vector<vector<int> > adj(maxn);
int anc[18][maxn]; 
// anc[i][j] 代表 j 的 2^i 倍祖先
// 紀錄到每一點的 2^17 倍祖先 (大於1e5) 

void dfs(int n, int fa, int d) {
    anc[0][n] = fa; // 一倍祖先就是父親
    dep[n] = d;
    for (int v : adj[n]) {
    	if (v != fa) dfs(v, n, d+1);
    }
}

void setupLCA() {
    dep[0] = -1;
    dfs(1, 0, 0);
    for (int i = 1; i < 18; i++) {
        for (int j = 1; j <= n; j++) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 17;i >= 0;i--) {
    	if (dep[anc[i][a]] >= dep[b]) {
        	a = anc[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 17;i >= 0;i--) {
    	if (anc[i][a] != anc[i][b]) {
        	a = anc[i][a];
            b = anc[i][b];
        }
    }
    return anc[0][a];
}

int main() {ios::sync_with_stdio(false);cin.tie(0);
    // 省略輸入圖
	int m;cin>>n>>m;
	for(int i=1; i<n; i++){
		int a, b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
    setupLCA();
    while (m--) {
        int u, v; 
        cin >> u >> v;
        cout <<dep[u]+dep[v]- 2*dep[lca(u, v)] << '\n';
    }
}
