#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  ll h[n];
  rep(i, n) cin >> h[i];
  ll dp[100010];
  rep(i, 100010) dp[i] = INF;

  // 初期条件
  dp[0] = 0;

  for (var i = 1; i < n; ++i) {
    // i番目の配列にはINFが入っている
    // この問題の文脈だと、i番目の足場
    // i番目の足場には、ここにくるまでの最小のスコアを記録したい。
    // そこで、INF と [i-1番目のスコア+移動スコア] と [i-2番目のスコア+移動スコア] の３パターンを比べて、
    // 最小の値を dp[i] に記録したい。

    chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    if (i > 1) {
      chmin(dp[i], dp[i-2] + abs(h[i] - h[i - 2]));
    }
  }

  cout <<  dp[n-1] << endl;
}
