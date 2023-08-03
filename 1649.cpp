#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;

#define lc(i) (i<<1)
#define rc(i) (i<<1^1)

typedef long long ll;

struct SegmentTree {
    int L;
    vector<ll> v;

    SegmentTree(int N): L(N), v(L << 1) {
        for (int i = N; i < (N << 1); i++) cin >> v[i];

        for (int i = N - 1; i > 0; i--) {
            v[i] = min(v[lc(i)] , v[rc(i)]);
        }
    }

    void modify(int i, ll d) {
		v[i+L]=d;
		i+=L;
        for ((i)>>=1; i; i >>= 1) v[i] = min(v[lc(i)] , v[rc(i)]);
    }

    ll query(int l, int r) {
        ll mini = INT32_MAX;
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) mini = min(mini,v[l++]);
            if (r & 1) mini = min(mini,v[--r]);
        }
        return mini;
    }
};


signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	SegmentTree st(n);
	while(m--){
		int det, a, b;cin>>det>>a>>b;
		if(det==1) st.modify(a-1, b);
		else cout<<st.query(a-1, b)<<'\n';
	}

}

