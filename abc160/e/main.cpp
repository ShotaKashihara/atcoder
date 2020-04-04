#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<ll> a(100010);
vector<ll> b(100010);
vector<ll> c(100010);
vector<ll> ab(100010);

int main() {
  ll x, y, _a, _b, _c;
  cin >> x >> y >> _a >> _b >> _c;
  a.resize(_a);
  b.resize(_b);
  c.resize(_c);
  ab.resize(x + y);

  rep(i, _a) cin >> a[i];
  rep(i, _b) cin >> b[i];
  rep(i, _c) cin >> c[i];

  // 赤いリンゴを逆ソートしてx個、緑いリンゴ逆ソートしてy個とって合成して逆ソートして、
  // 白いリンゴも逆ソートして、
  // 白いリンゴの先頭と赤緑リンゴの先頭を比較しつつ、白いほうが大きければswapするのを c だけ繰り返す

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  rep(i, x) {
    ab[i] = a[i];
  }
  rep(i, y) {
    ab[i + x] = b[i];
  }
  sort(ab.begin(), ab.end());
  sort(c.rbegin(), c.rend());

  int ab_cur = 0;
  rep(i, _c) {
    if (ab[ab_cur] < c[i]) {
      ab[ab_cur] = c[i];
      ab_cur++;
    }
  }

  ll ans = 0;
  rep(i, x + y) {
    ans += ab[i];
  }

  cout << ans << endl;

  return 0;
}
