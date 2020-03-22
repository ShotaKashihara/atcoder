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
  // 長さ
  int len = s.size();
  // 長さの半分分をループする
  int ans = 0;
  rep(i,(len+2-1)/2) {
    if (s[i] != s[len-1-i]) {
      ans += 1;
    }
  }

  cout << ans << endl;
  
  return 0;
}
