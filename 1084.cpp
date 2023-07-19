#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    int n, m, k;cin>>n>>m>>k;
    vector<int> appli(n+1);
    vector<int> apart(m+1);
    for(int i=0; i<n; i++) cin>>appli[i];
    for(int i=0; i<m; i++) cin>>apart[i];
    appli[n]=INT32_MAX;apart[m]=INT32_MAX;
    sort(appli.begin(), appli.end());
    sort(apart.begin(), apart.end());
    appli[n]=appli[n-1];
    apart[m]=apart[m-1];
    int app=0, apa=0, cnt=0;
    int chc=0;
    bool bla=false;
    while(app<n&&apa<m){
        //cout<<app<<' '<<apa<<' '<<cnt<<'\n';
        chc++;
        if(appli[app]>=apart[apa]-k&&appli[app]<=apart[apa]+k){
            //cout<<appli[app]<<' '<<apart[apa]<<' '<<cnt<<'\n';
            bla=false;
            cnt++;app++;apa++;
            
        }
        else if(appli[app]>apart[apa]+k){
            apa++;bla=true;
        }else if(appli[app]<apart[apa]-k){
            app++;
        }
        if(chc>n+m+100) break;
    }//cout<<app<<' '<<apa;
    if(bla){
        for(int i=app; i<n; i++){
            if(appli[i]>=apart[m-1]-k&&appli[i]<=apart[m-1]+k){
                cnt++;break;
            }
        }}
    cout<<cnt;
}