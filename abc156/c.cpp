#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {

  int n;
  cin >> n;
  int x[n];
  rep(i,0,n) cin >> x[i];

  // 100通り試せばOK

  ll res = INF;
  rep(i,1,100) {
    // (Z - x[i])^2 の総和
    ll sum = 0;
    rep(j,0,n) {
      sum += pow(i - x[j], 2.0);
    }
    chmin(res, sum);
  }

  cout << res << endl;

  return 0;
}
