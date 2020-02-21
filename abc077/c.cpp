#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  rep(i,0,n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  // 祭壇を満たす条件: a < b < c 
  // 上を満たす個数を求めたい。
  // これは ある b に着目したときに、 (a < b の個数) x (b < c の個数) ということになる.
  // これを b だけループしてあげれば答えが出る

  ll ans = 0;

  rep(i,0,n) {
    // a < b の個数
    var a_b_itr = lower_bound(a.begin(), a.end(), b[i]);
    ll a_b_count = a_b_itr - a.begin();

    // b < c の個数
    var b_c_itr = upper_bound(c.begin(), c.end(), b[i]);
    ll b_c_count = c.begin() - b_c_itr;

    ans += a_b_count * b_c_count;
  }
  cout << ans;
  return 0;
}
