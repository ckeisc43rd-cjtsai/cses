#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;
int lb(int x) {return x&(-x);}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	vector<int> li(n+1);
	for(int i=1; i<=n; i++){
		cin>>li[i];
	}
	int root=__lg(n);
	root=1<<(root);
	vector<int> bit(root*2, 0);
	for(int i=1; i<=n; i++){
		bit[i]=(i&(-i));
		if(bit[i]==0) bit[i]=i;
	}
	for(int i=1; i<=n; i++){
		int d;cin>>d;
		int cur=root, sum=bit[cur];
		while(cur&&(cur<=root*2)){
			if(sum<d){
				cur=cur+lb(cur);
				sum+=bit[cur];
			}else if(sum>d){
				int tmp=bit[cur];
				cur=cur-lb(cur)/2;

				sum=sum-tmp+bit[cur];
			}else{
				cout<<li[cur]<<' ';
				int tmp=cur;
				while(cur<=n){
					bit[cur]--;
					cur=cur+lb(cur);
				}
				break;
			}
		}
	}
}
