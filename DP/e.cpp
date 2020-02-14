#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX_ITEM = 100;
const int MAX_VALUE = 100000;
ll dp[MAX_ITEM][MAX_VALUE]; // 重さ

int main() {
  int n;
  ll w;
  cin >> n >> w;
  ll weight[n];
  ll value[n];
  rep(i,n) {
    cin >> weight[i] >> value[i];
  }

  // 最小化問題なので初期化
  rep(i,MAX_ITEM) {
    rep(j,MAX_VALUE) dp[i][j] = INF;
  }
  
  // N個の品物の数ループ
  rep(i,n) {
    // 価値が 0->10^3*100 になるまで 1+v 回ループ
    rep(limit, 1+MAX_VALUE) {
      // 選ばない場合
      chmin(dp[i+1][limit], dp[i][limit]);

      // 選びたい
      if (limit - value[i] >= 0) {
        // 選んだ
        chmin(dp[i+1][limit], weight[i] + dp[i][limit - value[i]]);
      }
    }
  }

  // 10^3*100 の1次配列中から dp[i][sum_v]<w を満たす sum_v を見つける
  ll res;
  rep(i,MAX_VALUE) {
    if(dp[n][i] <= w) res = i;
  }

  cout << res << endl;
}
