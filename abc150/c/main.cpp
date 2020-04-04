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

vector<int> p(100100); // 1e5
vector<int> q(100100); // 1e5

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  p.resize(n);
  q.resize(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];

  vector<int> a(n); // {}
  iota(all(a), 1); // {1,2,3}
  int count, ansq, ansp;
  do { 
    count++;
    if (a == p) ansp = count;
    if (a == q) ansq = count;
  } while (next_permutation(all(a)));

  cout << abs(ansp - ansq) << endl;
  return 0;
}
