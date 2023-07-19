#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    pii a, b;
    vector<vector<char>> graph(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
            if(graph[i][j]=='A') a={i, j};
            if(graph[i][j]=='B') b={i, j};
        }
    }
}