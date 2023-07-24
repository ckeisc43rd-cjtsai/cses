#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define pii pair<int, int>
#define int long long
#define ff first
#define ss second
using namespace std;
float eps=0.000006;

struct pt{
    int x,y;
    pt(int x, int y):x(x),y(y){};
};

pt operator+(const pt &a, const pt &b) {
    return pt(a.x + b.x, a.y + b.y);
} //向量相加

pt operator-(const pt &a, const pt &b) {
    return pt(a.x - b.x, a.y - b.y);
} //向量相減

pt operator*(int k, const pt &a) {
    return pt(a.x * k, a.y * k);
} //向量乘法（係數積）
pt operator*(const pt &a, int k) {
    return pt(a.x * k, a.y * k);
} // 乘法有交換率

pt operator/(const pt &a, int k) {
    return pt(a.x / k, a.y / k);
} //向量除法 (係數除法)

int operator^(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
} //向量外積cross

int operator*(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
} //向量內積dot

inline bool operator == (const pt &a, const pt &b){
    if(abs(a.x-b.x) <= eps && abs(a.y - b.y) <= eps) return true;
    return false;
}

//方向函數ori，回傳OA向量與OB向量的方向
int ori( const pt& a , const pt& b, const pt& o){	//方向函數
    double cross = ( a - o ) ^ ( b - o );
    if( fabs( cross ) < eps ) return 0;
    return cross > 0 ? 1 : -1;
}

bool onseg(pt a, pt b, pt o){         //o是否在ab線段上
    int cross = (a - o) ^ (b - o);    //是否平行
    int dot = (a - o) * (b - o);      //是否在線段中
    return (cross == 0)&&(dot <= 0);
}

bool banana(pt a, pt b, pt c, pt d){      //線段ab是否與cd相交
    if(onseg(a,b,c)||onseg(a,b,d)) return true;  //點c、d是否洽在線段ab上
    if(onseg(c,d,a)||onseg(c,d,b)) return true;  //點a、b是否洽在線段cd上
    return (ori(a,b,c)*ori(a,b,d) < 0 && ori(c,d,a)*ori(c,d,b) < 0);
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    while(n--){
        int x1, y1, x2, y2, x3, y3, x4, y4;cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        pt a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
        if(banana(a, b, c, d)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}