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
// 最小化問題なので INF で埋める

ll h[100010];

// dp[i] の最小コストを求める
ll rec(int i) {
  if (dp[i] < INF) return dp[i];

  if (i == 0) return 0;

  // dp[i] の最小コストは。dp[i-1] or dp[i-2] から計算できる
  ll res = INF;
  chmin(res, rec(i-1) + abs(h[i] - h[i-1]));
  if (i > 1) {
    chmin(res, rec(i-2) + abs(h[i] - h[i-2]));
  }

  dp[i] = res;
  return dp[i];
}

int main() {
  int n;
  cin >> n;
  rep(i,n) cin >> h[i];
  rep(i,100010) dp[i] = INF;

  cout << rec(n-1) << endl;
}
