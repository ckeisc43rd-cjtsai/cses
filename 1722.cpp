#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
#define ll long long
#define int long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mod = 1e9 + 7;

struct Mat {
    // n*n 方陣 
    vector<vector<ll>> A;
    int n;
    Mat(int _n){
        n=_n;
        for (int i = 0; i < n; ++i) {
            A.pb(vector<ll>(n));
        }
    }
};

Mat operator *(const Mat &m1, const Mat &m2) {
    assert(m1.n == m2.n);
    int n = m1.n;
    Mat ret(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ret.A[i][j] += m1.A[i][k] * m2.A[k][j];
                ret.A[i][j] %= mod;
            }
        }
    }
    return ret;
}

Mat pow (Mat a, int n) {
    Mat ans(a.n);
    for (int i = 0; i < a.n; ++i) {
        ans.A[i][i]=1;
    } // 斜角化
    for (int i=1;i<=n;i<<=1) {
        if (n&i) ans = ans * a;
        a = a * a;
    }
    return ans;
}



signed main(){_
    int n;
    cin >> n;
    Mat K(2);
    K.A = {
        {1,1},
        {1,0}};
           
    Mat I(2);
    I.A = {
        {0,0},
        {1,0}
    };

    Mat R = pow(K, n) * I; // R = (K^n) * I
    cout << R.A[0][0];
    return 0;
}
