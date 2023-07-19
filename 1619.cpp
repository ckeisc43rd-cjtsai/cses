#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    vector<int> arrive(n);
    vector<int> leave(n);
    for(int i=0; i<n; i++) cin>>arrive[i]>>leave[i];
    sort(arrive.begin(), arrive.end());
    sort(leave.begin(), leave.end());
    int arr=0, lea=0, cnt=0, max=INT32_MIN;
    while(arr<n&&lea<n){
        if(arrive[arr]<leave[lea]){
            cnt++;arr++;
            if(cnt>max) max=cnt;
        }else if(arrive[arr]>leave[lea]){
            cnt--;lea++;
        }else{
            arr++;lea++;
        }
    }cout<<max;
}