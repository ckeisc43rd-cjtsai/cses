#include <bits/stdc++.h>
using namespace std;
#define int long long
#define modd 1000000007
vector<int> dp(100007, 0);
struct trie{
	trie* c[26];
	int cnt=0;
	trie(){
		memset(c, 0, sizeof(c));
	}
};
trie* root = new trie();
 
void insert(string s){
	trie* tmp = root;
	for(int i=s.size()-1; i>=0; i--){
		if(!tmp->c[(s[i]-'a')]){
			tmp->c[(s[i]-'a')] = new trie();
		}
		tmp=tmp->c[(s[i]-'a')];
	}tmp->cnt++;
}
string ans;
void query(int e){
	trie* tmp =root;
	int tpe=e;
	while(tpe>=0){
		int eee=ans[tpe]-'a';
		if(tmp->c[eee]){
			tmp=tmp->c[eee];
		}else{
			break;
		}if(tmp->cnt){
			dp[tpe]+=dp[e+1];
			dp[tpe]%=modd;
		}tpe--;
	}
 
}
 
signed main(){
	cin>>ans;
	int n;cin>>n; 
	for(int i=0; i<n; i++){
		string t;cin>>t;
		insert(t);
	}
	dp[ans.size()]=1;
	for(int i=ans.size()-1; i>=0; i--){
		query(i);
	}cout<<dp[0];
}
