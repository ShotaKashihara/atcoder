#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
ll dp[100010][3];

int main() {
  int n;
  cin >> n;
  ll a[100010][3];
  rep(i,n) {
    rep(j,3) cin >> a[i][j];
  }


  // 最小化問題なので INF で埋める
  // rep(i,100010) dp[i] = 0;
  // dp[0] = 0;

  rep(i,n) {
    rep(j,3) {
      rep(k,3) {
        if (j == k) continue;
        chmax(dp[i+1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  ll res = 0;
  rep(i,3) {
    chmax(res, dp[n][i]);
  }
  
  cout << res << endl;
}
