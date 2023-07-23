#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<bool> li(n+1);
    int tmp=n*(n+1)/2;
    if(tmp%2==1){
        cout<<"NO";
        return 0;
    }
    tmp/=2;
    cout<<"YES\n";
    int cnt=0;
    for(int i=n; i>=1; i--){
        if(i<=tmp){
            //cout<<i<<' '<<tmp<<'\n';
            tmp-=i;
            cnt++;
            li[i]=1;
        }
        if(tmp==0) break;
    }
    cout<<cnt<<'\n';
    for(int i=1; i<=n; i++) if(li[i]) cout<<i<<' ';
    cout<<'\n'<<n-cnt<<'\n';
    for(int i=1; i<=n; i++) if(!li[i]) cout<<i<<' ';
}