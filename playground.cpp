#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
using ll = long long;


ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
ll pow(ll x, ll n, ll mod) {
  ll ans = 1;
  while(n != 0){
      if(n&1) ans = ans*x % mod;
      x = x*x % mod;
      n = n >> 1;
  }
  return ans;
}

// nが大きくて、kが小さい場合の comb(n,k) ※計算量 O(k) 
// comb(n,k)  = (n*(n-1)*...*(n-k+1)) / k!

int factorial(int n, int mod) {
  return (n == 1) ? 1 : n * factorial(n - 1, mod) % mod;
}

ll comb(int n, int k, int mod) {
  ll res = 1;
  rep(i, n-k+1, k) {
    res *= i;
    res %= mod;
  }
  res *= pow(factorial(k, mod), mod-2, mod);
  res %= mod;
  return res;
}

ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
rep(i,1,a+1) {
  temp = temp*(n+1-i)%MOD*invp(i,MOD)%MOD;
}

int main() {
  int mod = 1000000007;

  // cout << comb(4, 2, mod) << endl;
  // cout << comb(4, 3, mod) << endl;
  // cout << comb(4, 4, mod) << endl;

  ll w = pow(2, 1000000000, mod) - 1;
  ll a = comb(1000000000, 141421, mod);
  ll b = comb(1000000000, 173205, mod);
  cout << w - a - b << endl;
}

// 140625000
// 516595147
// 589953354