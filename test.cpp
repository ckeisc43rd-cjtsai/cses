#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<int> li;
    for(int i=1; i<=10; i++) li.push_back(i);
    sort(li.begin(), li.end());
    cout<<li[0]<<' '<<li[9];   
    
    }