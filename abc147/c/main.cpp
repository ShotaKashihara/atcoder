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

vector<vector<P>> v(15, vector<P>(15));

vector<vector<bool>> bit_full_search(int N) {
  vector<vector<bool>> res;
  res.resize(1<<N);
  for (int bit = 0; bit < (1<<N); bit++) {
    rep(i,N) {
      res.at(bit).push_back((bit & 1<<i));
    }
  }
  return res;
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);

  int n;
  cin >> n;

  v.resize(n);
  rep(i,n) {
    int a;
    cin >> a;
    v.at(i).resize(a);
    rep(j,a) {
      int x,y; cin >> x >> y;
      v.at(i).at(j) = P(x,y);
    }
  }

  // 嘘か真か調べ上げる
  auto res = bit_full_search(n);
  int ans = 0;
  for (auto x: res) {
    bool success = true;
    rep(i,n) {
      auto vv = v.at(i);
      for (auto p: vv) {
        if (x.at(i)) {
          if (p.second != x.at(p.first-1)) {
            success = false;
          }
        }
      }
    }
    if (success) {
      ans = max(ans, accumulate(all(x), 0));
    }
  }

  cout << ans << endl;

  return 0;
}
