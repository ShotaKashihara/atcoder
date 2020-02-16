#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
  int n; cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];

  int res = 0;
  while (true) {
    // すべて偶数
    bool allEven = true;
    rep(i,n) {
      if (a[i] % 2 == 1) {
        allEven = false;
        break;
      }
    }

    if (allEven) {
      res++;
      rep(i,n) {
        a[i] = a[i] / 2;
      }
    } else {
      break;
    }
  }
  cout << res << endl;
  return 0;
}
