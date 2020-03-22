#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  // 回文である
  rep(i,n/2) {
    if (s[i] != s[n-1-i]) {
      ok = false;
    }
  }
  // s[0] から s[(n-1)/2] までが回文
  // i: 0~ (n-1)/2 - 1
  rep(i, n/4) {
    // auto a = s[i];
    // auto b = s[(n-1)/2-1-i];
    if (s[i] != s[(n-1)/2-1-i]) {
      ok = false;
    }
  }

  rep(i, n/4) {
    // auto a = s[i + (n+3) / 2 - 1];
    // auto b = s[n - 1 - i];
    if (s[i + (n+3) / 2 - 1] != s[n - 1 - i]) {
      ok = false;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
