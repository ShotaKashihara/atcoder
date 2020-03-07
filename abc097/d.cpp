#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> par;
  UnionFind(int N): par(N) {
    rep(i, 0, N) par[i] = i;
  }
  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

int main() {
  // input
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);

  int p[n];
  rep(i, 0, n) cin >> p[i];

  // calculation
  int x, y;
  rep(i, 0, m) {
    cin >> x >> y;

    // ごにょごにょして
    uf.unite(x, y);
  }

  // p[i] == i の数を数える
  int res = 0;
  rep(i, 0, n) {
    res += (uf.same(p[i], i+1)) ? 1 : 0;
  }
  cout << res << endl;
}
