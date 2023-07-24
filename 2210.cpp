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
int pow(int a, int b){
    int ans=1;
    if(b==0) return 0;
    if(b==1) return a;
    if(b%2){
        int tmp=pow(a, b/2);
        return ((tmp*tmp)%modd)*a%modd;
    }else{
        int tmp=pow(a, b/2);
        return (tmp*tmp)%modd;
    }return 0;
}
/*
THIS QUESTION IS THE APPLICATION OF BURNSIDE LEMMA
*/
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    int tmp=n*n;
    if(n%2) cout<<(((pow(2, tmp)+pow(2, (n/2)*(n/2+1)+2)+pow(2, (tmp+1)/2))%modd)*pow(4, modd-2))%modd;
    else cout<<(((pow(2, tmp)+pow(2, (n/2)*(n/2)+1)+pow(2, (tmp+1)/2))%modd)*pow(4, modd-2))%modd;
}
