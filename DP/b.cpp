#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
ll dp[100010];

int main() {
  int n, k;
  cin >> n >> k;
  ll h[100010];
  rep (i,n) cin >> h[i];
  // 最小化問題なので INF で埋める
  rep(i,100010) dp[i] = INF;

  dp[0] = 0;

  rep (i,n) {
    for (int j = 1; j <= k; ++j) {
      chmin(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
    }
  }
  cout << dp[n-1] << endl;
}
