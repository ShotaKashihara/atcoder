#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<pair<int, int>>> v;

int main() {
  int n;
  cin >> n;
  v.resize(n);
  rep(i,n) {
    int a;
    cin >> a;
    v[i].resize(a);
    rep(j,a) {
      int x,y;
      cin >> x >> y;
      v[i][j] = P(x,y);
    }
  }

  int ans = n+1;
  rep(i, 1<<n) {
    bool ok = true;
  
    for (auto p: v[i]) {
      // iさんの発言がどれか偽なら、この検証は不要とする

      if (i & 1 << p.first ^ p.second) {
        ok = false;
      }
    }

    if (ok) {
      min(ans, counter(i));
    }
  }

  cout << v[0][0].first << endl;
  return 0;
}
