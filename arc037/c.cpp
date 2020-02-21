#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
#define all(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];

  sort(all(a));
  sort(all(b));

  // a[i] * b[i] を並べたものを ab[] として、k番目を求める
  // 小さい方から K番目の値が X である
  // 言い換えると、「X-1以下の数は K個未満かつ、X以下の数はK個以上ある」
  // 1,1,2,2,2,2,2,4,4
  // 小さい方から 7番目は 2
  // 1以下の数は 2個 < 7個
  // 2以下の数は 7個

  // 更に言い換えて、「X以下の数が K個以上あるような最小のX」が小さい方からK番目の数
  // Xを固定して、「X以下の数はK個以上あるか？」をisOK() にして二分探索

  


  return 0;
}
