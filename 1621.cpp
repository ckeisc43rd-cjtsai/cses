#include <iostream>
#include <set>

using namespace std;

signed main(){
    int n;cin>>n;
    set<int> ans;
    while(n--){
        int a;cin>>a;
        ans.insert(a);
    }cout<<ans.size();
}