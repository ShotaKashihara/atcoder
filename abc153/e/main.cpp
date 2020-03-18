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

  // cost を 1ずつ増やしていって、damage が HP を超えたら終了
  // → damage の最大化問題
  // index: cost
  // value: damage

  int ans = 0;
  rep(cost, INF) {
    // ちょうど 合計cost になるような選択肢のうち、damage が最大のものを選ぶ
    rep(i, n) {
      int damage = p[i].first;
      int _cost = p[i].second;
      if (cost-_cost < 0) continue;
      chmax(dp[cost], damage + dp[cost-_cost]);
    }

    if (dp[cost] >= h) {
      ans = cost;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
