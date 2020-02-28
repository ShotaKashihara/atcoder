#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

  // auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  
  // 3 2
  // 1 1 1
  // 0 2 1
  // 0 3 0
  // → 0 と 0以外の組み合わせは
  // 0 0 X ... 1
  // 0 X 0 ... 1
  // X 0 0 ... 1
  // 0 X X ... 2
  // X 0 X ... 2
  // X X 0 ... 2
  // X X X ... 1
  
  // 0の個数を i とすると
  // → nCi x ???

  // 0 0 (111)
  // 0 (111) 0 ... 1
  // (111) 0 0 ... 1
  // 0 (11) (1) ... 2
  // 0 (1) (11) ... 2
  // (11) 0 (1) ... 2
  // (1) 0 (11) ... 2
  // (11) (1) 0 ... 2
  // (1) (11) 0 ... 2
  // (1) (1) (1) ... 1
  // → 0の個数が i のとき、0以外の個数は (n-i)
  // → (n-i) 個の部屋に 1以上を割り当てて、和が n になるようにしたい
  // 0 () () ← 3こいれたい
  // () には必ず 1 が一個以上ははいるので
  // 0 (1) (1) ← 1個いれたい
  //           ← n-(n-i) 個入れたい
  // ということになる。
  // 0 (1) (1) に n-(n-i) 個入れる comb は、
  // 2つの箱に 1 を 1個入れる組み合わせなので、 2 になる。
  // もし、4つの箱に、2個入れる場合
  // 11|||1       1 の個数=n-(n-i), 仕切りの個数=0以外の個数-1= (n-i)-1
  // n-(n-i)+(n-i)-1 C n-(n-i) という組み合わせを求めれば良い
  

  k = min(n-1,k);
  combination c(n);
  mint ans;
  rep(i, 0, k+1) {
    ans += c(n,i) * c(n-1, i);
  }
  
  cout << ans.x << endl;
  return 0;
}
