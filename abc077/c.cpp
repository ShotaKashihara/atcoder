#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(a) (a).begin(),(a).end()
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

  sort(all(a));
  sort(all(b));
  sort(all(c));

  // 祭壇を満たす条件: a < b < c 
  // 上を満たす個数を求めたい。
  // これは ある b に着目したときに、 (a < b の個数) x (b < c の個数) ということになる.
  // これを b だけループしてあげれば答えが出る

  ll ans = 0;

  rep(i,0,n) {
    // a < b の個数
    var l_i = lower_bound(all(a), b[i]);
    ll l_c = l_i - a.begin();

    // b < c の個数
    var u_i = upper_bound(all(c), b[i]);
    ll u_c = c.end() - u_i;

    ans += l_c * u_c;
  }
  cout << ans << endl;
  return 0;
}
