#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX_ITEM = 110;
const int MAX_VALUE = 100100;
ll dp[MAX_ITEM][MAX_VALUE] = {0};

int main() {
  // 最小化問題なので INF で埋める
  rep(i,100010) dp[i][0] = INF;
  dp[0][0] = 0;
  
  cout << dp[n-1][0] << endl;
}
