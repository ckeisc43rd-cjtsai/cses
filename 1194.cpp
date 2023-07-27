#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define ff first
#define ss second
#define int long long
using namespace std;

const int dx[4]={0, 0, 1, -1};
const int dy[4]={-1, 1, 0, 0};

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    pii a, b;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<pii>> pa(n, vector<pii>(m, {-1, -1}));
    vector<vector<int>> depth(n, vector<int>(m));
    vector<vector<int>> md(n, vector<int>(m, INT32_MAX));
    queue<piii> mon;
    queue<piii> bfs;
    pii end={-1, -1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j]=='M'){
                mon.push({0,{i, j}});
                md[i][j]=0;
                }
            if(graph[i][j]=='A') a={i, j};
            if(graph[i][j]=='A'&&((i==0||i==n-1)||(j==0||j==m-1))) {end={i, j};goto bla;}
        }
    }
    while(!mon.empty()){
        piii tmp=mon.front();mon.pop();{
            for(int i=0; i<4; i++){
                if(tmp.ss.ff+dx[i]>=n||tmp.ss.ss+dy[i]>=m||tmp.ss.ff+dx[i]<0||tmp.ss.ss+dy[i]<0) continue;
                if(graph[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]=='#') continue;
                if(md[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]>tmp.ff+1){
                    md[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]=tmp.ff+1;
                    mon.push({md[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]], {tmp.ss.ff+dx[i],tmp.ss.ss+dy[i]}});
                }
            }
        }
    }
    
    graph[a.ff][a.ss]='@';
    pa[a.ff][a.ss]=a;
    bfs.push({0,a});
    //cout<<md[7][1];
    while(!bfs.empty()){
        piii tmp=bfs.front();bfs.pop();
        //cout<<tmp.ss.ff<<' '<<tmp.ss.ss<<tmp.ff<<'\n';
        //cout<<tmp.ff<<' '<<tmp.ss<<'\n';
        for(int i=0; i<4; i++){
            if(tmp.ss.ff+dx[i]>=n||tmp.ss.ss+dy[i]>=m||tmp.ss.ff+dx[i]<0||tmp.ss.ss+dy[i]<0) continue;
            if(md[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]<=tmp.ff+1) continue;
            if(graph[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]=='.'){
                graph[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]='@';
                pa[tmp.ss.ff+dx[i]][tmp.ss.ss+dy[i]]=tmp.ss;
                if((tmp.ss.ff+dx[i]==0||tmp.ss.ff+dx[i]==n-1||tmp.ss.ss+dy[i]==0||tmp.ss.ss+dy[i]==m-1)){
                    end={tmp.ss.ff+dx[i],tmp.ss.ss+dy[i]};
                    goto bla;
                }
                bfs.push({tmp.ff+1, {tmp.ss.ff+dx[i],tmp.ss.ss+dy[i]}});
            }
        }
    }
    bla:
    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<md[i][j]<<' ';
        }cout<<'\n';
    }*/
    if(end.ff==-1){
        cout<<"NO";
        //return 0;
    }else{
        vector<char> ans;
        pii tmp=end;
        while(tmp!=a){
            //cout<<tmp.ff<<' '<<tmp.ss<<'\n';
            pii tp2=pa[tmp.ff][tmp.ss];
            int dyy=tp2.ff-tmp.ff;
            int dxx=tp2.ss-tmp.ss;
            if(dxx==-1) ans.push_back('R');
            else if(dxx==1) ans.push_back('L');
            else if(dyy==1) ans.push_back('U');
            else if(dyy==-1) ans.push_back('D');
            tmp=tp2;
        }
        cout<<"YES\n"<<ans.size()<<'\n';
        for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
    }
}