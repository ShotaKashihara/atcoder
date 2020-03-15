#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  ll h, w;
  cin >> h >> w;

  if (h == 1 || w == 1) {
    cout << 1 << endl;
  } else if (h%2 == 0 && w%2 == 0) {
    cout << w * h/2 << endl;
  } else if (h%2 == 1 && w%2 == 1) {
    cout << (w/2+1)*(h/2+1) + (w/2) * (h/2) << endl;
  } else {
    cout << (w*h)/2 << endl;
  }

  return 0;
}
