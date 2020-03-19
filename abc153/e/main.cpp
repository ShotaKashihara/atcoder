#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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
ll dp[MAX_ITEM] = {0};

int main() {
  int h,n;
  cin >> h >> n;
  vector<P> p(n);

  rep (i, n) {
    double a,b;
    cin >> a >> b;
    p[i] = P(a,b);
  }

  // 最小化問題なので、INF で埋める
  rep(i,h+1) dp[i] = INF;
  // 最初はzero
  dp[0] = 0;

  // あるHPまでに最小の魔力をDPしていく
  // dp[<HP>] = <COST> 
  rep(i,h+1) {
    // 選択肢の数だけ試す
    rep(j,n) {
      int damage = p[j].first;
      int cost = p[j].second;
      chmin(dp[ min(h, i+damage) ], dp[i] + cost);
    }
  }

  cout << dp[h] << endl;
  return 0;
}
