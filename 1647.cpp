#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

/*
---------------------
|this segment tree  |
|is zero-based      |
|and lclose ropen   |
|no lazy propagation|
---------------------
*/

struct segtree{
    vector<int> v;
    int L;
    segtree(int n):L(n), v(2*n){
        for(int i=n; i<2*n; i++){
            cin>>v[i];
        }
        for(int i=n-1; i>0; i--){
            v[i]=min(v[2*i], v[2*i+1]);
        }
    }
    void addmodify(int t, int d){
        for(int i=t+L; i>0; i/=2) v[i]+=d;
    }
    void setmodify(int t, int d){
        int tmp=v[t+L]-d;
        for(int i=t+L; i>0; i/=2) v[i]-=tmp;
    }

    int query(int l, int r){
        int ans=INT32_MAX;
        for(int dl=l+L, dr=r+L; dl<dr; dl/=2, dr/=2){
            //cout<<dl<<' '<<dr<<'\n';
            if(dl%2==1){
                ans=min(ans, v[dl]);
                dl++;
            }
            if(dr%2==1){
                dr--;
                ans=min(ans,v[dr]); 
            }
        }
        return ans;
    }
    void test(){
        for(int i=1; i<2*L; i++) cout<<v[i]<<'\n';
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    segtree st(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        cout<<st.query(a-1, b)<<'\n';
    }
}