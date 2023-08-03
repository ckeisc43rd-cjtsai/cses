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
    vector<ll> v, sz, tag;

    SegmentTree(int N): L(N), v(L << 1), sz(L << 1, 1), tag(L << 1) {
        for (int i = N; i < (N << 1); i++) cin >> v[i];

        for (int i = N - 1; i > 0; i--) {
            v[i] = v[lc(i)] + v[rc(i)];
            sz[i] = sz[lc(i)] + sz[rc(i)];
        }
    }

    void update(int i, ll d) {
        v[i] += d * sz[i];
        tag[i] += d;
    }

    void pull(int i) {
        for (int h = __lg(L) + 1; h; h--) {
            int p = i >> h;
            if (tag[p]) {
                update(lc(p), tag[p]);
                update(rc(p), tag[p]);
                tag[p] = 0;
            }
        }
    }

    void push(int i) {
        for (i >>= 1; i; i >>= 1) {
            v[i] = v[lc(i)] + v[rc(i)] + tag[i] * sz[i];
        }
    }

    void modify(int l, int r, ll d) {
        int ll = l + L, rr = r + L - 1;
        pull(ll), pull(rr);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) update(l++, d);
            if (r & 1) update(--r, d);
        }
        push(ll), push(rr);
    }

    ll query(int l, int r) {
        ll sum = 0;
        pull(l + L), pull(r + L - 1);
        for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sum += v[l++];
            if (r & 1) sum += v[--r];
        }
        return sum;
    }
};
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;cin>>n>>m;
	SegmentTree st(n);
	while(m--){
		int det;cin>>det;
		if(det==1){
			int a, b, c;cin>>a>>b>>c;
			st.modify(a-1, b, c);
		}else{
			int a;cin>>a;
			cout<<st.query(a-1, a)<<'\n';
		}
	}
}

