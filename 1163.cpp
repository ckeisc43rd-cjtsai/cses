#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    vector<int> ori(m);
    vector<int> shuf(m);
    map<int, int> fro;
    map<int, int> end;
    for(int i=0; i<m; i++){
        int a;cin>>a;
        ori[i]=a;shuf[i]=a;
    }sort(shuf.begin(), shuf.end());
    for(int i=1; i<m; i++){
        fro[shuf[i]]=shuf[i-1];
    }
    for(int i=0; i<m-1; i++){
        end[shuf[i]]=shuf[i+1];
    }
    fro[shuf[0]]=0;
    end[shuf[m-1]]=n;
    int tmp=shuf[0];
    for(int i=1; i<m; i++){
        if(shuf[i]-shuf[i-1]>tmp) tmp=shuf[i]-shuf[i-1];
    }
    tmp=max(tmp, n-shuf[m-1]);
    vector<int> ans;
    for(int i=m-1; i>=0; i--){
        ans.push_back(tmp);
        int tpp=ori[i];
        //cout<<"sss:"<<fro[tpp]<<' '<<end[tpp]<<" "<<tpp<<'\n';
        if(end[tpp]-fro[tpp]>tmp)tmp=end[tpp]-fro[tpp];
        end[fro[tpp]]=end[tpp];
        fro[end[tpp]]=fro[tpp];
    }
    for(int i=m-1; i>=0; i--) cout<<ans[i]<<' ';
}