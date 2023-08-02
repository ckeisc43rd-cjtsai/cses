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
    int n, m;cin>>n>>m;
    vector<vector<int>> presum(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        string a;cin>>a;
        for(int j=1; j<=n; j++){
            presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
            if(a[j-1]=='*') presum[i][j]++;
        }
    }
    for(int i=0; i<m; i++){
        int x1,x2, y1, y2;cin>>x1>>y1>>x2>>y2;
        cout<<presum[x2][y2]-presum[x2][y1-1]-presum[x1-1][y2]+presum[x1-1][y1-1]<<'\n';
    }
}