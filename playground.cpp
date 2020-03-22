#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int a = 50000;
  long long  l = 50000;

  long long ans;

  ans = a*a;
  cout << ans << endl; // -1794967296 ← overflowしてる
  ans = (ll)a*a;
  cout << ans << endl; // -1794967296 ← overflowしてる
  ans = l*l;
  cout << ans << endl; // 2500000000
}
