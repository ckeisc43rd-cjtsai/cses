#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define pii pair<int, int>
//#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0; i<n; i++){
        int ans=0;
        int a;cin>>a;
        int tmp=sqrt(a);
        for(int i=1; i<=tmp; i++){
            if(a%i==0){
                ans+=2;
            }if(i*i==a) ans--;
        }cout<<ans<<'\n';
    }
}