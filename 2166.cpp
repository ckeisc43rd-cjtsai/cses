using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
#define int long long
struct node{
	int val, sum, pre;
	//node(val):val(val){};
};
int n, q;

vector<int> a(200005);
vector<node> segtree(800005);
void pull(int x) {
    segtree[x].pre = max(segtree[2*x].sum+segtree[2*x+1].pre, segtree[2*x].pre);
	segtree[x].sum=segtree[2*x].sum+segtree[2*x+1].sum;
}
void build(int l, int r, int x) {
    if(l == r) {
        segtree[x].val = a[l];
		segtree[x].sum = a[l];
		segtree[x].pre = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * x), build(mid + 1, r, 2 * x + 1);
    pull(x);
}
void modify(int p, int v, int l, int r, int x) {
    if(l == r) {
        segtree[x].val = v;
		segtree[x].pre=v;
		segtree[x].sum=v;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) modify(p, v, l, mid, 2 * x);
    else modify(p, v, mid + 1, r, 2 * x + 1);
    pull(x);
}
ll sumquery(int ql, int qr, int l, int r, int x) {
    if(ql == l && qr == r) return segtree[x].sum;
    int mid = (l + r) / 2;
    if(qr <= mid) return sumquery(ql, qr, l, mid, 2 * x);
    else if(mid < ql) return sumquery(ql, qr, mid + 1, r, 2 * x + 1);
    return sumquery(ql, mid, l, mid, 2 * x)+ sumquery(mid + 1, qr, mid + 1, r, 2 * x + 1);
}
ll query(int ql, int qr, int l, int r, int x) {
    if(ql == l && qr == r) return segtree[x].pre;
    int mid = (l + r) / 2;
    if(qr <= mid) return query(ql, qr, l, mid, 2 * x);
    else if(mid < ql) return query(ql, qr, mid + 1, r, 2 * x + 1);
    return max(query(ql, mid, l, mid, 2 * x), sumquery(ql, mid, l, mid, 2*x)+query(mid + 1, qr, mid + 1, r, 2 * x + 1));
}


signed main() {
        cin >> n >> q;
    //segtree.resize(4 * n);
    //a.resize(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, n, 1);
    while(q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) modify(a, b, 1, n, 1);
        else cout <<max((int)0, query(a, b, 1, n, 1)) << '\n';
    }
    return 0;
}
