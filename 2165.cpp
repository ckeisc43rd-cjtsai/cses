#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

void hanoi(int from, int to, int amo){
    if(amo==1) cout<<from<<' '<<to<<'\n';
    else{
        hanoi(from, 6-from-to, amo-1);
        hanoi(from, to, 1);
        hanoi(6-from-to, to, amo-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    cout<<pow(2, n)-1<<'\n';
    hanoi(1, 3, n);
}