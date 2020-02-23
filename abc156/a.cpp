#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n, r;
  cin >> n >> r;

  if (n > 9) {
    cout << r << endl;
  } else {
    cout << (r + (100 * (10 - n))) << endl;
  }

  return 0;
}
