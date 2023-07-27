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
    int n;cin>>n;
    vector<int> li(n+1);
    for(int i=1; i<=n; i++) li[i]=i;
    vector<bool> taken(n+1, 0);
    int cnt=0;
    int pnt=2;
    if(n==1){
        cout<<1;return 0;
    }
    while(true){
        taken[pnt]=true;
        cout<<pnt<<' ';
        cnt++;
        if(cnt==n) break;
        while(taken[pnt]==true) pnt=(pnt)%n+1;
        pnt=pnt%n+1;
        while(taken[pnt]==true) pnt=pnt%n+1;
    }
}