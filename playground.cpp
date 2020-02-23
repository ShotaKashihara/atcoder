#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
using ll = long long;

ll pow(ll x, ll n, int mod) {
  ll ans = 1;
  while(n != 0){
      if(n&1) ans = ans*x % mod;
      x = x*x % mod;
      n = n >> 1;
  }
  return ans;
}

ll nCr(int n, int r, int mod) {
  ll res = 1;
  for(int i = 1; i <= r; i++) {
    res = res * (n-i+1) % mod * pow(i, mod-2, mod) % mod;
  }
  return res;
}

int main() {
  int mod = 1000000007;
  int n,a,b;
  cin >> n >> a >> b;
  ll temp = pow(2, n, mod) - 1 - nCr(n, a, mod) - nCr(n, b, mod);
  // ※  temp が 負mod より小さい場合も考える。(このif文は理解のためにつけているので、実際は if分岐せずに処理しても良い)
  if (temp < mod) {
    temp %= mod;
    temp += mod; 
  }
  temp %= mod;
  cout << temp << endl;
}
