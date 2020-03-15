#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;
using ld = long double;

int main() {

  ld a,b,c;
  cin >> a >> b >> c;

  if (a + (2 * sqrt(a*b)) + b - c < 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
