#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,0,n) cin >> p[i];

  // 累積和
  vector<int> s(n+1, 0);
  rep(i,0,n) {
    s[i+1] = s[i] + p[i];
  }

  // 最大を探す
  int i_max = 0;
  int s_max = 0;
  rep(i, 0, n-k+1) {
    if (s_max < (s[i+k] - s[i])) {
      i_max = i;
      s_max = s[i+k] - s[i];
    }
  }

  double m = 0;
  rep(i,i_max,k) {
    m += (double)(1+p[i])/2;
  }
  cout << fixed << setprecision(12) << m << endl;

  return 0;
}
