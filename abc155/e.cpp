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
  s += '0';
  int n = s.size();
  rep(i,n)rep(j,2) {
    dp[i][j] = INF;
  }

  dp[0][0] = 0;

  rep(i,n) {
    int x = s[i] - '0';
    chmin(dp[i+1][0], dp[i][0] + x);
    chmin(dp[i+1][1], dp[i][0] + (10 - x));
    chmin(dp[i+1][0], dp[i][1] + x + 1);
    chmin(dp[i+1][1], dp[i][1] + (10 - x - 1));
  }

  cout << dp[n][0] << endl;

  return 0;
}
