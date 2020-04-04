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

ll a[1000100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y;
  cin >> n >> x >> y;

  x--;
  y--;

  // i -> j への最短経路を考える
  // 経路のパターンは最大3つ
  // 1. i -> j へ ショートカットを使わずに直線で移動する
  // 2. i -> x, y -> j へショートカットを使って移動する
  // 3. i -> y, x -> j へショートカットを使って移動する

  rep(i, n) {
    rep(j, i + 1, n) {
      int dist = abs(i - j);
      dist = min(dist, abs(i - x) + 1 + abs(j - y));
      dist = min(dist, abs(i - y) + 1 + abs(j - x));
      a[dist]++;
    }
  }

  rep(i, 1, n) {
    cout << a[i] << endl;
  }

  return 0;
}
