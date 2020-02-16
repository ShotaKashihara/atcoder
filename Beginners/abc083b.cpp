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

// 12345,0 -> 1234,5 -> 123,9 -> 12,12 -> 1,14

int digit_sum(int n, int sum) {
  if (n < 10) {
    return sum + n;
  }
  return digit_sum(n / 10, sum + n % 10);
}

int main() {
  int n,a,b; cin >> n >> a >> b;

  int res = 0;
  rep(i,n+1) {
    var sum = digit_sum(i,0);
    if (a <= sum && sum <= b) {
      res += i;
    }
  }

  cout << res << endl;
  return 0;
}
