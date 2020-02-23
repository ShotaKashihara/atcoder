#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
using namespace std;
using ll = long long;


// 二項係数の和
// 例えば n=4 のとき
// 1. c(4,0) + c(4,1) + c(4,2) + c(4,3) + c(4,4)
// = 1+4+6+4+1
// = 2^4
// (Option) 2. c(4,0) - c(4,1) + c(4,2) - c(4,3) + c(4,4)
// = 1-4+6-4+1
// = 0
// ()

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  ll n,a,b;
  cin >> n >> a >> b;

  // 前処理
  COMinit();

  // 計算例
  ll sum = 0;
  rep(i, 1, n+1) {
    if (i == a || i == b) continue;
    sum += COM(n, i);
    sum = sum % MOD;
  }
  
  cout << sum << endl;
  return 0;
}
