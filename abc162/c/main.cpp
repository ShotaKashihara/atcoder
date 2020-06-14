#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b+a); ++i)
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;

  ll sum = 0;

  rep(a,k) rep(b,k) rep(c,k) {
    ll aa;
    aa = gcd(a+1, b+1);
    aa = gcd(aa, c+1);
    sum += aa;
  }
  
  cout << sum << endl;

  return 0;
}
