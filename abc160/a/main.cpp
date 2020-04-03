#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] && s[4] == s[5]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
