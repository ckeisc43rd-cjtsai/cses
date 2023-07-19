#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<pii> li(n);
    for(int i=0; i<n; i++){
        int a;cin>>a;
        li[i]={a, i};
    }
    sort(li.begin(), li.end());
    int tmp=li[0].ss, cnt=1;
    for(int i=1; i<n; i++){
        if(li[i].ss<tmp) cnt++;
        tmp=li[i].ss;
    }cout<<cnt;
}