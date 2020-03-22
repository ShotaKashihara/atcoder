#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int a = 50000;
  long long  l = 50000;

  // long long ans;

  long long ans = 50000 * 50000;
  cout << ans << endl; // overflow

  long long ans = (long long)50000 * 50000;
  cout << ans << endl; // 2500000000

  // ans = a*a;
  // cout << ans << endl; // -1794967296 ← overflowしてる
  // ans = (ll)a*a;
  // cout << ans << endl; // -1794967296 ← overflowしてる
  // ans = l*l;
  // cout << ans << endl; // 2500000000


}
