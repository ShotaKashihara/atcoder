#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  string s,t,u;
  int a,b;
  cin >> s >> t;
  cin >> a >> b;
  cin >> u;

  if (u == s) {
    cout << a-1 << " " << b << endl;
  } else {
    cout << a << " " << b-1 << endl;
  }

  return 0;
}
