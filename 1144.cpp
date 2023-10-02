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
const int MAXN=(int)2e5+7;
vector<int> ori(MAXN);
vector<int> v(2*MAXN, 0);
struct segtree{
    int L=MAXN;
    segtree(int n, int re){
        for(int i=0; i<re; i++){
            int a;cin>>a;v[a+n]++;
            ori[i]=a;
        }
        for(int i=n-1; i>0; i--){
            v[i]=v[2*i]+v[2*i+1];
        }
    }
    void addmodify(int t, int d){
        for(int i=t+L; i>0; i/=2) v[i]+=d;
    }
    void setmodify(int t, int d){
        int tmp=v[t+L]-d;
        for(int i=t+L; i>0; i/=2) v[i]-=tmp;
    }
 
    int sumquery(int l, int r){
        int ans=0;
        for(int dl=l+L, dr=r+L; dl<dr; dl/=2, dr/=2){
            //cout<<dl<<' '<<dr<<'\n';
            if(dl%2==1){
                ans+=v[dl];
                dl++;
            }
            if(dr%2==1){
                dr--;
                ans+=v[dr]; 
            }
        }
        return ans;
    }
    int minquery(int l, int r){
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
 
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;cin>>n>>m;
    segtree st(MAXN, n);
    for(int i=0; i<m; i++){
        char ss;cin>>ss;
        if(ss=='!'){
            int ta, tb;cin>>ta>>tb;
            ta--;
            st.addmodify(ori[ta], -1);
            st.addmodify(tb, 1);ori[ta]=tb;
        }else{
            int ta, tb;cin>>ta>>tb;
            cout<<st.sumquery(ta, tb+1)<<'\n';
        }
    }
}

