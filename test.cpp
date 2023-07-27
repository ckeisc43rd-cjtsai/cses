#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#pragma GCC optimize("Ofast")
#define pii pair<int, int>
#define int long long
#define inta __int128_t
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> groups(m+1);
    vector<vector<int>> which(n+1);
    vector<int> visited(n+1, 0);
    vector<inta> distance(n+1, INT64_MAX);
    for(int i=0; i<m; i++){
        int cnt, maxi;cin>>cnt>>maxi;
        groups[i].push_back(maxi);
        for(int j=0; j<cnt; j++){
            int c;cin>>c;
            groups[i].push_back(c);
            which[c].push_back(i);
        }
    }
    if(m==1){
        if(groups[0].size()==n+1){
            cout<<groups[0][0];
        }else{
            cout<<-1;
        }
        return 0;
    }
    //visited[1]=1;
    distance[1]=0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        //cout<<'P'<<u<<'\n';
        if (visited[u]) continue;
        visited[u] = 1;
        for(int i=0; i<which[u].size(); i++){
            for(int j=1; j<groups[which[u][i]].size(); j++){
                inta w=groups[which[u][i]][0];
                int v=groups[which[u][i]][j];
                if (distance[v] <= distance[u] + w) continue;
    
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }int maxi=INT32_MIN;
    for(inta x: distance){
        if(x>maxi&&x!=INT64_MAX&&x>0) maxi=x;
    }if(maxi==INT32_MIN) cout<<-1;
    else cout<<maxi;
    
}