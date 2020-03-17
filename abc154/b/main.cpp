#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  rep(i,0,s.length()) {
    s[i] = 'x';
  }
  cout << s << endl;
  return 0;
}
