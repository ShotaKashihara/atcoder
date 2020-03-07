#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int a,b;
  cin >> a >> b;

  int ans = -1;
  rep(i, 0, 1100) {
    // 税率8%のとき i==a
    if (floor(i*0.08) == a && floor(i*0.1) == b) {
      ans = i;
      break;
    }
  }

  if (ans == -1) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
