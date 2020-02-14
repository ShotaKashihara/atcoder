#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
ll dp[1000][100010] = {0};

int main() {
  int n, w;
  cin >> n >> w;
  ll weight[n];
  ll value[n];
  rep(i,n) {
    cin >> weight[i] >> value[i];
  }

  // N個の品物の数ループ
  rep(i,n) {
    // 重さが 0->w になるまで 1+w 回ループ
    rep(limit, 1+w) {

      // 品物iの重さが上限より小さいか？
      // :eyes: 0-1 ナップザックなので、置けるか置かないかだけ見ている
      if (limit - weight[i] >= 0) {
        // 上で代入した、選ばない場合と選ぶ場合の最大を取る
        chmax(dp[i+1][limit], value[i] + dp[i][limit - weight[i]]);
      }
      // 品物iを選ばない場合
      // そのままコピー
      chmax(dp[i+1][limit], dp[i][limit]);
    }
  }  

  cout << dp[n][w] << endl;
}
