#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

ll a[100010];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;

  rep(i, n) {
    rep(j, i + 1, n) {
      // 抜け道を使った場合の距離
      // 1から5まで歩いた
      int dist = abs(i - j);

      // 抜け道Xを使った場合の距離
      // 1からx まで歩く + 1 + yから5まで歩く
      int distx = abs(x - i) + 1 + abs(y - j);

      // 抜け道Yを使った場合の距離
      // 1からyまで歩く + 1 + xから5まで歩く
      int disty = abs(y - i) + 1 + abs(x - j);

      dist = min(dist, distx);
      dist = min(dist, disty);
      a[dist]++;
    }
  }

  rep(i, 1, n) {
    cout << a[i] << endl;
  }

  return 0;
}
