#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    int n, m;cin>>n>>m;
    vector<int> ticket(n);
    vector<int> human(m);
    vector<bool> taken(n, 0);
    for(int i=0; i<n; i++) cin>>ticket[i];
    sort(ticket.begin(), ticket.end());
    //for(auto x:ticket) cout<<x<<' ';
    for(int i=0; i<m; i++) cin>>human[i];
    for(int i=0; i<m; i++){
        int l=0, r=n;
        while(r-1>l){
            if(l==n-1) break;
            int mid=(l+r)/2;
            if(human[i]>=ticket[mid]){
                l=mid;
            }else if(human[i]<ticket[mid]){
                r=mid-1;
            }
        }
        for(; l>=0; l--){
            if(!taken[l]){
                taken[l]=true;
                break;
            }
        }
        if(l==-1){
            cout<<-1<<'\n';
        }else cout<<ticket[l]<<'\n';
    }
}