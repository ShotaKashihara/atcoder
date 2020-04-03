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

vector<int> a(200010);

int main() {
  int k,n;
  cin >> k >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];

  // a[0] から a[0] までぐるっと一周まわる
  // かつ、差分が一番大きい場所をメモしておく

  int sum = 0;
  int max_diff = 0;
  rep(i,n) {
    if (i == 0) {
      sum += k + a[0] - a[n-1];
      max_diff = max(k + a[0] - a[n-1], max_diff);
    } else {
      sum += a[i] - a[i-1];
      max_diff = max(a[i] - a[i-1], max_diff);
    }
  }

  cout << sum - max_diff << endl;

  return 0;
}
