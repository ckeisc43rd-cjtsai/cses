#include <bits/stdc++.h>
using namespace std;
const int dx[4]={0, 0, -1, 1};
const int dy[4]={-1, 1, 0, 0};
bool vis[9][9];
string s;
int cnt=0;
void enumerate(int n, int x, int y, int dir){
	if(x==7&&y==1){
		if(n!=48) return;
		cnt++;//cout<<'k';cout.flush();
		return;
	}
	if(n==48) return;
	if(vis[x+dx[0]][y+dy[0]]&&vis[x+dx[1]][y+dy[1]]&&!vis[x+dx[2]][y+dy[2]]&&!vis[x+dx[3]][y+dy[3]]) return;
	if(!vis[x+dx[0]][y+dy[0]]&&!vis[x+dx[1]][y+dy[1]]&&vis[x+dx[2]][y+dy[2]]&&vis[x+dx[3]][y+dy[3]]) return;
	int dire=-1;
	if(s[n]=='R') dire=1;
	if(s[n]=='L') dire=0;
	if(s[n]=='D') dire=3;
	if(s[n]=='U') dire=2;
	if(dire!=-1){
		int i=dire;
		if(vis[x+dx[i]][y+dy[i]]) return;
		if(!vis[x+dx[i]][y+dy[i]]){
			vis[x+dx[i]][y+dy[i]]=1;
			enumerate(n+1, x+dx[i], y+dy[i], i);
			vis[x+dx[i]][y+dy[i]]=0;
		}
		return;
	}

	for(int i=0; i<4; i++) {
		if(vis[x+dx[i]][y+dy[i]]) continue;
		if(!vis[x+dx[i]][y+dy[i]]){
			vis[x+dx[i]][y+dy[i]]=1;
			enumerate(n+1, x+dx[i], y+dy[i], i);
			vis[x+dx[i]][y+dy[i]]=0;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++)
			vis[i][j]=0;
	}
	for(int i=0; i<9; i++) vis[0][i]=1, vis[i][0]=1, vis[8][i]=1, vis[i][8]=1;
	cin>>s;
	vis[1][1]=1;
	enumerate(0, 1, 1, 1);
	//vis[0][0]=1;
	cout<<cnt;
}
