#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
// sort(A.begin(), A.end(), cmp)
bool cmp(P a, P b) { return a.second < b.second; }
#ifdef DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
#else
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#endif
const ll INF = 1LL << 60;
const int MAX_ITEM = 10e4+10; // 10^5
ll dp[1000010][2] = {0};

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  s += '0'; // 91 とか、繰り上がりの桁が必要なことがある
  int n = s.size();
  rep(i,n+1)rep(j,2) {
    dp[i][j] = INF;
  }
  // 0: くりさがりなし 1: くりさがりあり
  dp[0][0] = 0;

  // 91
  // dp[i桁目][0] = i桁で繰り下がりなしの場合のi桁目までの最小の枚数
  // dp[i桁目][1] = i桁で繰り下がりありの場合のi桁目までの最小の枚数


  // 88
  // res = 2 + 1 + 1

  //1. 8
    // dp[0][0] = 0
    // dp[0][1] = 0

    // 8
    // dp[0][0] = 8
    // dp[0][1] = 2

    // 8
    // dp[1][0] = dp[0][0] + 8, dp[0][1] + (8 + 1) = 11
    // dp[1][1] = dp[0][0] + (10-8) or dp[0][1] + (10 - (8 + 1)) = 3

    // 0
    // dp[2][0] = dp[1][0] + 0, dp[1][1] + 1 = 4
    // dp[2][1] = dp[1][0] + (10-8) or dp[1][1] + (10 - (8 + 1)) = 3


  rep(i,n)rep(j,2) {
    int x = s[i] - '0';

    // i-1桁目で繰り下がりがない場合
    chmin(dp[i+1][0], dp[i][0] + x);  // くりさがりなし
    chmin(dp[i+1][1], dp[i][0] + (10 - x)); // くりさがりあり

    if (i-1 > 0) {
      chmin(dp[i+1][0], )
    }
  }

  return 0;
}
