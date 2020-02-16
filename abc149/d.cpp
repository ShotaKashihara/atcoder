#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> a(3);
  rep(i, 3) cin >> a[i];
  string s;
  cin >> s;
  vector<int> ctoi(256);
  ctoi['r'] = 2;
  ctoi['s'] = 0;
  ctoi['p'] = 1;
  int ans = 0;
  rep(i, k) {
    vector<int> x;
    // 1: rrr
    // 2: sp
    for (int j = i; j < n; j += k) {
      x.push_back(ctoi[s[j]]);
    }
    // 1: 222
    // 2: 01
    var prev = -1;
    for (var nx : x) {
      if (prev == nx) {
        ans += 0;
        // cout << "[" << ans << "]" << endl;
        prev = -1;
      } else {
        ans += a[nx];
        // cout << "[" << ans << "]" << endl;
        prev = nx;
      }
    }
  }
  cout << ans << endl;
}
