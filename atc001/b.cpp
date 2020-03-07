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
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);

  // calculation
  int p, a, b;
  rep(i, 0, q) {
    cin >> p >> a >> b;
    if (p == 0) {
      // 連結
      uf.unite(a,b);
    } else {
      // 判定
      cout << (uf.same(a,b) ? "Yes" : "No") << endl; 
    }
  }

  return 0;
}
