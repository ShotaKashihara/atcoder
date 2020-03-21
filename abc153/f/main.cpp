#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> a;
int main() {
  int n,d,a;
  cin >> n >> d >> a;
  vector<P> xh(n);
  rep(i,n) {
    int x,h; cin >> x >> h;
    xh[i] = P(x, h);
  }

  // 座標順にソートしてみる
  sort(xh.begin(), xh.end(), [](P p1, P p2) {
    return p1.first < p2.first;
  });

  ll ans = 0;
  // 左側から爆破
  rep(i, n) {
    // 最初の 座標とHP
    int index = xh[i].first;
    int hp = xh[i].second;
    // HP をゼロにするのに必要な爆弾の数
    int bomb = (hp%a == 0) ? hp/a : hp/a +1;
    ans += bomb;
    // index から周辺 d にいるやつのHPを削る
    rep(j,n) {
      if (xh[j].first - index <= (d*2)) {
        xh[j].second -= bomb*a;
      }
    }
  }

  return 0;
}
