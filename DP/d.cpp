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
  int n, w;
  cin >> n >> w;
  ll w[n];
  ll v[n];
  rep(i,n) {
    cin >> w[i] >> v[i];
  }

  ll dp[110][100010] = {0};

  // 
  // dp[i] 価値の総和の最大値

  // N個の品物の数ループ
  rep(i,n) {
    // 重さの和が 0->w になるようにループ
    for (var sum_w = 0; sum_w <= w; ++sum_w) {

      // i番目の品物を選ぶ場合
      // → sum_w - w[i] の価値に v[i] を加算
      if (sum_w - w[i] >= 0) {
        chmax(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i]);
      }

      // i番目の品物を選ばない場合
      // → いま(dp[i])と全く同じなのでコピー
      chmax(dp[i+1][sum_w], dp[i][sum_w]);
    }
  }  



  cout << dp[n-1] << endl;
}
