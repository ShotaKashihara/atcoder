#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間加算にも対応した BIT
template <class Abel> struct BIT {
  vector<Abel> dat[2];
  Abel UNITY_SUM = 0; // to be set

  /* [1, n] */
  BIT(int n) { init(n); }
  void init(int n) {
    for(int iter = 0; iter < 2; ++iter)
      dat[iter].assign(n + 1, UNITY_SUM);
  }

  /* a, b are 1-indexed, [a, b) */
  inline void sub_add(int p, int a, Abel x) {
    for(int i = a; i < (int)dat[p].size(); i += i & -i)
      dat[p][i] = dat[p][i] + x;
  }
  inline void add(int a, int b, Abel x) {
    sub_add(0, a, x * -(a - 1));
    sub_add(1, a, x);
    sub_add(0, b, x * (b - 1));
    sub_add(1, b, x * (-1));
  }

  /* a is 1-indexed, [a, b) */
  inline Abel sub_sum(int p, int a) {
    Abel res = UNITY_SUM;
    for(int i = a; i > 0; i -= i & -i)
      res = res + dat[p][i];
    return res;
  }
  inline Abel sum(int a, int b) {
    return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) -
           sub_sum(1, a - 1) * (a - 1);
  }

  /* debug */
  void print() {
    for(int i = 1; i < (int)dat[0].size(); ++i)
      cout << sum(i, i + 1) << ",";
    cout << endl;
  }
};

vector<int> a;
int main() {
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> xh(n);
  rep(i, n) {
    int x, h;
    cin >> x >> h;
    xh[i] = P(x, h);
  }

  // 座標順にソートしる
  sort(xh.begin(), xh.end(), [](P p1, P p2) { return p1.first < p2.first; });

  ll ans = 0;
  // 左側から爆破
  rep(i, n) {
    // 最初の 座標とHP
    int index = xh[i].first;
    int hp = xh[i].second;
    if(hp <= 0) {
      continue;
    }
    // HP をゼロにするのに必要な爆弾の数
    int bomb = (hp % a == 0) ? hp / a : hp / a + 1;
    ans += bomb;
    // index から周辺 d にいるやつのHPを削る
    rep(j, n) {
      if(xh[j].first - index <= (d * 2)) {
        xh[j].second -= bomb * a;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
