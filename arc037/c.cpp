#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];

  sort(all(a));
  sort(all(b));

  // あるXを 1~10^18 の範囲で二分探索したい。
  // 条件
  // 小さい方から 3番目の値は 10 となる
  // 小さい方から K番目の値は X となる
  // →→ X以下の個数はK個以上である

  // ある値 X を取ったときに満たす条件
  // X >= a_i * b_j
  // 変形して
  // b_j <= X/a_i
  // K を求めたいので、この式を満たす個数を数える
  // var count = upper_bound(all(b), x / a[i]);
  // if sum(count) ok = mid;
  // else ng = mid;


  ll ng = 1;
  ll ok = INF;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    ll sum = 0;

    rep(i,0,n) {
      ll count = upper_bound(all(b), mid / a[i]) - b.begin();
      sum += count;
    }

    if (sum >= k) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
  return 0;
}
