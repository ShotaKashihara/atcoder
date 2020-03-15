#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = a; i < (a+n); i++)
#define var auto
using namespace std;
using ll = long long;

int n;

void dfs(string s, char mx) {
  if (s.length() == n) {
    cout << s << endl;
  } else {
    rep(i, 0, mx - 'a' + 1) {
      char c = 'a'+i;
      if (mx == c) {
        dfs(s+c, mx+1);
      } else {
        dfs(s+c, mx);
      }
    }
  }
}

int main() {
  // cin >> n;
  n = 3;

  // dfs("", 'a');

  string s = "";
  rep(i,0,'z'-'a'+1) {
    s += 'a' + i;
  }
  cout << s << endl;

  return 0;
}
