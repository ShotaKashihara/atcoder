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

void resolver(int keta, ll value, vector<ll> &all) {
  all.push_back(value);

  if (keta == 10) return;

  // keta + 1 を列挙する
  // value = 1 だったら
  // 10, 11, 12
  // value = 23 だったら
  // 231, 232, 233
  rep(i, -1, 3) {
    int add = (value%10) + i;
    if (add >= 0 && add <= 9) {
      resolver(keta+1, value*10+add, all);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k;
  cin >> k;

  vector<ll> all;

  // 最初の桁が 1~9のものを全列挙する
  rep(i,1,9) {
    resolver(1, i, all);
  }

  sort(all(all));

  cout << all[k-1] << endl;

  return 0;
}
