#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define int long long
#define ss second
using namespace std;

int power(int a, int b){
    if(b==0) return 1;
    int tmp=a;
    for(int i=1; i<b; i++) tmp*=a;
    return tmp;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin>>n;
    vector<int> li(n);
    int sum=0;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        sum+=a;li[i]=a;
    }
    int tmp=power(2, n), maxi=INT32_MAX;
    for(int i=0; i<tmp; i++){
        int rrr=i;
        int cnt=0, amo=0;
        while(rrr){
            if(rrr%2){
                amo+=li[cnt];
            }cnt++;rrr/=2;
        }if(abs(sum-2*amo)<maxi) maxi=abs(sum-2*amo);
    }cout<<maxi;
}