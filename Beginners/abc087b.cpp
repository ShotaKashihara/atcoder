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
  int a,b,c,x;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;

  int res = 0;
  rep(a_i,a+1) {
    rep(b_i,b+1) {
      rep(c_i,c+1) {
        if (a_i*500+b_i*100+c_i*50 == x) {
          res++;
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
