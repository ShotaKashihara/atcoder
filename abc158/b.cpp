#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll amari = n;
  bool is_a = true;
  ll res = 0;

  if (a == 0) {
    cout << 0 << endl;
    return 0;
  } else if (b == 0) {
    cout << n << endl;
    return 0;
  }

  ll s1 = n / (a+b);
  ll s2 = n % (a+b);
  cout << s1*a + min(s2, a) << endl;
  
  

  // while (amari > 0) {
  //   if (is_a) {
  //     res += min(a, amari);
  //     amari -= a;
  //     is_a = false;
  //   } else {
  //     amari -= b;
  //     is_a = true;
  //   }
  // }

  // cout << res << endl;
  return 0;
}
