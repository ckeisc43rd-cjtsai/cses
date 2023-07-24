#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define pii pair<int, int>
#define int unsigned long long
#define ff first
#define ss second
using namespace std;

int modd=1e9+7;
int power(int k, int t){
    if(t==0) return 1;
    if(t==1) return k;
    int ans=1;
    while(t){
        if(t%2){
            int tmp=power(k, t/2);
            return ((tmp*tmp)%modd*k)%modd;
        }else{
            int tmp=power(k, t/2);
            return (tmp*tmp)%modd;
        }
    }return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int arr[1000007];
    arr[1]=1;
    for(int i=2; i<1000005; i++){
        arr[i]=(arr[i-1]*i)%modd;
    }int n;cin>>n;
    if(n%2){
        cout<<0;
        return 0;
    }n/=2;
    int a=2*n, b=n;
    int tmp=((arr[a]*power(arr[b], modd-2))%modd*power(arr[a-b], modd-2))%modd;
    if(a==b) tmp=1;
    b=n+1;
    int tp2=((arr[a]*power(arr[b], modd-2))%modd*power(arr[a-b], modd-2))%modd;
    if(a==b) tp2=1;
    cout<<(tmp+modd-tp2)%modd;
}