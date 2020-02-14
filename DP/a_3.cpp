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
  rep(i,n) cin >> h[i];

  ll dp[n];
  rep(i,n) dp[i] = INF;

  dp[0] = 0;

  for (var i = 0; i < n, ++i) {
    chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }

  cout << dp[n-1] << endl;
}
