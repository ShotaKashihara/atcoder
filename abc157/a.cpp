#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n; cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << endl;
  } else {
    cout << n / 2 + 1 << endl;
  }
  return 0;
}
