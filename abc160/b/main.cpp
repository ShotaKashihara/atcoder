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
  int x;
  cin >> x;

  ll ans = 0;
  ans += x/500*1000;
  x = x%500;
  ans += x/5*5;

  cout << ans << endl;

  return 0;
}
