#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

const int dx[4]={0, 0, 1, -1};
const int dy[4]={-1, 1, 0, 0};

int main(){
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    pii a, b;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<pii>> pa(n, vector<pii>(m, {-1, -1}));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j]=='A') a={i, j};
            if(graph[i][j]=='B') b={i, j};
        }
    }
    queue<pii> bfs;
    graph[a.ff][a.ss]='@';
    pa[a.ff][a.ss]=a;
    bfs.push(a);
    while(!bfs.empty()){
        pii tmp=bfs.front();bfs.pop();
        //cout<<tmp.ff<<' '<<tmp.ss<<'\n';
        for(int i=0; i<4; i++){
            if(tmp.ff+dx[i]>=n||tmp.ss+dy[i]>=m||tmp.ff+dx[i]<0||tmp.ss+dy[i]<0) continue;
            if(graph[tmp.ff+dx[i]][tmp.ss+dy[i]]!='@'&&graph[tmp.ff+dx[i]][tmp.ss+dy[i]]!='#'){
                graph[tmp.ff+dx[i]][tmp.ss+dy[i]]='@';
                pa[tmp.ff+dx[i]][tmp.ss+dy[i]]=tmp;
                if(tmp.ff+dx[i]==b.ff&&tmp.ss+dy[i]==b.ss){
                    goto bla;
                }
                bfs.push({tmp.ff+dx[i],tmp.ss+dy[i]});
            }
        }
    }
    bla:
    if(pa[b.ff][b.ss].ff==-1){
        cout<<"NO";
        return 0;
    }else{
        vector<char> ans;
        pii tmp=b;
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