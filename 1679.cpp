#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
#define MAXN 500
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<vector<int>> can(n+1);
    vector<vector<int>> need(n+1);
    vector<int> siz(n+1);
    vector<int> time(n+1, 0);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        can[a].push_back(b);
        need[b].push_back(a);
    }
    stack<int> dfs;
    for(int i=1; i<=n; i++){
        siz[i]=need[i].size();
        if(siz[i]==0) dfs.push(i);
    }
    int cnt=1;
    while(!dfs.empty()){
        int tmp=dfs.top();dfs.pop();
        time[tmp]=cnt;cnt++;
        for(int x:can[tmp]){
            if(time[x]) continue;
            siz[x]--;
            if(siz[x]<=0){
                dfs.push(x);
            }
        }
    }
    bool suc=true;
    vector<int> ans(n);
    for(int i=1; i<=n; i++){
        if(time[i]==0) {suc=false;continue;}
        ans[time[i]-1]=i;
    }
    if(suc){
        for(int x:ans) cout<<x<<' ';
    }else{
        cout<<"IMPOSSIBLE";
    }
}