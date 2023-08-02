#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define modd 1000000007

signed main(){
	int n, m;cin>>n>>m;
	//vector<int> val(n, 0);
	int a;cin>>a;
	int tmp=a, tct=1, cnt=0,ans=1;
	if(a==0){
		tct=1;
	}else{
		tct=0;
	}
	vector<vector<int> > val(2,vector<int>(m+1, tct));
	val[0][a]=1;
	//for(int x:val[0]) cout<<x<<' ';
	//cout<<'\n';
	for(int i=1; i<n; i++){
		cin>>a;
		if(a==0){
			for(int j=1; j<=m; j++){
				val[i%2][j]=0;
				if(j+1<=m)val[i%2][j]=(val[i%2][j]+val[(i+1)%2][j+1])%modd;
				if(j-1>=1)val[i%2][j]=(val[i%2][j]+val[(i+1)%2][j-1])%modd;
				val[i%2][j]=(val[i%2][j]+val[(i+1)%2][j])%modd;
			}
		}else{
			cnt=0;
			if(a+1<=m) cnt=(cnt+val[(i+1)%2][a+1])%modd;//cout<<cnt<<" 1\n";
			if(a-1>=1) cnt=(cnt+val[(i+1)%2][a-1])%modd;//cout<<cnt<<" 2\n";
			cnt=(cnt+val[(i+1)%2][a])%modd;//cout<<cnt<<" 3\n";
			//cout<<i<<' '<<val[(i+1)%2][a+1]<<' '<<val[(i+1)%2][a]<<'\n';
			for(int j=1; j<=m; j++){
				val[i%2][j]=0;
			}ans=(ans*cnt)%modd;
			val[i%2][a]=1;
		}//cout<<ans<<' ';
		//for(int x:val[i%2]) cout<<x<<' ';
		//cout<<'\n';
	}cnt=0;
	for(int i=1; i<=m; i++){
		cnt=(cnt+val[(n+1)%2][i])%modd;//cout<<cnt<<' ';
	}ans=(cnt*ans)%modd;
	cout<<ans;
}
