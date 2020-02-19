#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> aa(n*n);
  rep(i, n)rep(j, n) {
      aa.push_back(a[i] + a[j]);
  }
  sort(aa.rbegin(), aa.rend());
  ll ans = 0;
  rep(i, m) {
    ans += aa[i];
  }

  cout << ans << endl;
}
