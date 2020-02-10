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
    for (int j = i; j < n; j += k) {
      x.push_back(ctoi[s[j]]);
    }
  }
  rep(i, n) {
    
    bool skip = true;
    cout << "i: " <<  i << endl;
    if (s.length() > (max(i - 2, 0))) {
      if (s[i] != s[i - 2]) {
        ans += a[ctoi[s[i]]];
      } else if (skip) {
        skip = false;
        ans += a[ctoi[s[i]]];
      } else {
        skip = true;
      }
      cout << "ans: " <<  ans << endl;
    }
  }
  cout << ans << endl;
}
