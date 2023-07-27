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

struct disjointSet {
    vector<int> master, depth;

    disjointSet(int vertexCount) {
        master.resize(vertexCount);
        depth.resize(vertexCount);

        for (int i = 0; i < vertexCount; i++) {
            master[i] = i;
            depth[i] = 1;
        }
    }

    int query(int i) {
        if (master[i] == i) return i;

        return master[i] = query(master[i]);
    }

    void merge(int a, int b) {
        a = query(a);
        b = query(b);

        if (a == b) return;

        if (depth[a] < depth[b]) swap(a, b);
        master[b] = a;
        depth[a] += depth[b];
    }
}; // 記得分號
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    disjointSet dsu(n+1);
    for(int i=1; i<=n; i++){
        int a;cin>>a;
        if(a==i) continue;
        dsu.merge(a, i);
    }
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        if(dsu.query(a)==dsu.query(b)){
            cout<<abs(dsu.depth[a]-dsu.depth[b])<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
}