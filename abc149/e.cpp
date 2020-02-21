#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N; ll M; int A[101010];
//---------------------------------------------------------------------------------------------------
ll getCount(int tot) { // Ax + Ay = tot
    ll res = 0;
    rep(i, 0, N) {
        int Ay = tot - A[i]; // Ay = tot - Ax
        int idx = lower_bound(A, A + N, Ay) - A; // Ay の先頭からの位置
        res += N - idx; // 累積和 = パターンの数を合算
    }
    return res;
}
//---------------------------------------------------------------------------------------------------
ll As[101010];
ll getSum(int tot) {
    rep(i, 0, N) As[i] = A[i];
    rrep(i, N - 2, 0) As[i] += As[i + 1];

    ll res = 0;
    rep(i, 0, N) {
        int Ay = tot - A[i];
        int idx = lower_bound(A, A + N, Ay) - A;
        int cnt = N - idx;
        res += 1LL * A[i] * cnt;
        res += As[idx];
    }
    return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N);

    int ok = 0, ng = inf;
    while (ok + 1 != ng) { // ok と ng の差が 1 になるまでループ
        int md = (ok + ng) / 2; // ok と ng の中間点
        if (M <= getCount(md)) ok = md; // md 
        else ng = md;
    }
    // 上から3番目は Ax + Ay = 67 ということを2分探索で求めた
    ll ans = (M - getCount(ok + 1)) * ok + getSum(ok + 1);
    cout << ans << endl;
}
