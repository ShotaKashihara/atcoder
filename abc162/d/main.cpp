#pragma region Macros
#include <bits/stdc++.h>
#define int long long
using ll = long long;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(ll i = ll(a); i < ll(b+a); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#pragma endregion

signed main() {  
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;

  // r,g,b のすべての組み合わせ
  // - r,g,b の組み合わせかつ index の差が等しい

  int ac = 0,gc = 0,bc = 0;

  rep(i,n) {
    if (s[i] == 'R') {
      ac += 1;
    } else if (s[i] == 'G') {
      gc += 1;
    } else if (s[i] == 'B') {
      bc += 1;
    }
  }
  // すべての組み合わせ
  ll sum = ac*gc*bc;

  // index の差が等しい
  ll minus = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int k = j + j - i;
      if (k >= n) continue;
      if (s[i] == s[j] || s[i] == s[k] || s[j] == s[k]) continue;
      minus++;
    }
  }
  
  cout << sum - minus << endl;

  return 0;
}
