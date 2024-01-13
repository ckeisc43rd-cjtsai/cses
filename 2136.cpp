#include <bits/stdc++.h>
#define pii pair<int, int>
//#define int long long
#define ff first
#define ss second
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, k;cin>>n>>k;
	int arr[n]={
		0
	};
	int zzz[31];
	zzz[0]=1;
	for(int i=1; i<31; i++) zzz[i]=zzz[i-1]*2;
	for(int i=0; i<n; i++){
		string a;cin>>a;
		for(int j=0; j<k; j++) if(a[j]=='1') arr[i]+=zzz[j];
	}
	int mini=100;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==j) continue;
			int d=arr[i]^arr[j];
			int sum=0;
			while(d){
				if(d%2) sum++;
				d/=2;
			}
			if(sum<mini) mini=sum;
		}
	}cout<<mini;
}
