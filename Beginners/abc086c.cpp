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
  int t[n],x[n],y[n];
  rep(i,n) {
    cin >> t[i] >> x[i] >> y[i];
  }

  int c_x = 0;
  int c_y = 0;
  int c_t = 0;
  rep(i,n) {
    int min = abs(x[i] - c_x) + abs(y[i] - c_y);
    int d_t = t[i] - c_t;
    if (d_t < min || (d_t - min) % 2 == 1) {
      cout << "No" << endl;
      return 0; 
    }
  }
  cout << "Yes" << endl;
  return 0;
}
