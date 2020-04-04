#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<int> a(100100); // 1e5

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,k,m;
  cin >> n >> k >> m;

  a.resize(n-1);

  rep(i,n-1) cin >> a[i];

  int ans = m*n - accumulate(all(a), 0);
  if (0 <= ans && ans <= k) {
    cout << ans << endl;
  } else if (ans < 0) {
    cout << 0 << endl;
  } else {
    cout << "-1" << endl;
  }


  return 0;
}
