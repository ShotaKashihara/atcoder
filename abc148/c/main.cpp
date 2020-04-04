#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

// 最大公約数: greatest common divisor
ll gcd(ll a, ll b) { if (b == 0) return a; else return gcd(b, a % b); }
// 最小公倍数: least common multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
  int a,b;
  cin >> a >> b;

  cout << lcm(a,b) << endl;
}
