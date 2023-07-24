#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define int long long
#define ss second
using namespace std;
int modd=1e9+7;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int arr[n+10];
    if(n==1){cout<<0;return 0;}
    arr[2]=1;
    for(int i=3; i<=n; i++){
        arr[i]=(i*arr[i-1]+(i%2?-1:1))%modd;
    }cout<<arr[n];
}