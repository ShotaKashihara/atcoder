#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

vector<int> ac(100100); // 1e5
vector<int> wa(100100); // 1e5

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  ac.resize(n);
  wa.resize(n);

  rep(i,m) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (ac.at(p) == 0) {
      if (s == "AC") {
        ac.at(p) += 1;
      }
      if (s == "WA") {
        wa.at(p) += 1;
      }
    }
  }

  int wan = 0;
  rep(i, n) {
    if (ac.at(i) == 1) {
      wan += wa.at(i);
    }
  }
  cout << accumulate(all(ac), 0) << " " << wan << endl;

  return 0;
}
