# atcoder

## Algorithm
- 二分探索
  - ABC077 C
  - ARC037 C
- 桁DP
  - ABC155 E

## C++

### cin
N
A1 A2 ... AN
```c++
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
  for(T& x: vec) is >> x;
  return is;
}
vector<int> A(n);
cin >> A;
```

### char
abcdefghijklmnopqrstuvwxyz
```c++
string s = "";
rep(i, 0, 'z'-'a'+1) {
  s += 'a' + i;
}
cout << s << endl;
```
a
b
c
...
```c++ 
rep(i, 0, 'z'-'a'+1) {
  char c = 'a' + i;
  cout << c << endl;
}
```

### Vector
```c++
// サイズなし初期化
vector<int> a;
rep(i,0,n) {
    int _a; cin >> _a;
    a.push_back(_a);
}

// サイズあり初期化
vector<int> a(n);
rep(i,0,n) cin >> a[i];
```

```c++
#define all(a) (a).begin(),(a).end()

// asc sort
sort(all(A));

// desc sort
sort(A.rbegin(), A.rend());

// compあり sort
sort(all(A), [](int a1, int a2) {
  return a1 > a2;
});
```
## lower_bound, upper_bound

```c++
#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

int main() {
  int target = 51;

  sort(all(a));
  auto l_i = lower_bound(all(a), target);
  auto u_i = upper_bound(all(a), target);

  cout << "target: " << target << endl;
  cout << "array.size(): " << a.size() << endl;
  cout << "array: ";
  rep(i,0,a.size()) cout << a[i] << ",";
  cout << endl;
  
  // 51
  cout << "(*lower_bound)target以上の最初の値: " << *l_i << endl;
  // 243
  cout << "(*upper_bound)targetより大きいの最初の値: " << *u_i << endl;

  // 3
  cout << "(lower_bound)target未満の個数:" << l_i - a.begin() << endl;
  // 7
  cout << "(lower_bound)target以上の個数:" << a.end() - l_i << endl;
  // 4
  cout << "(upper_bound)target以下の個数:" << a.end() - u_i << endl;
  // 6
  cout << "(upper_bound)targetより大きい個数:" << u_i - a.begin() << endl;

  // 3
  cout << "(upper - lower)targetと同値の個数:" << u_i - l_i << endl;
}
```

## 二分探索 (binary_search)

[ARC037 C - 億マス計算](arc037/c.cpp)

```
vector<int> a = { 1,2,3,4,5,6,7,7,8,9 };

int main() {
  int key = 7;
  int ng = -1; // 左端の初期値
  int ok = a.size(); // 右端の初期値

  // 左端と右端の差が1になるまで。
  while (abs(ok - ng) > 1) {
    var mid = (ok - ng) / 2;
    if (a[mid] >= key) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
}
```

## DP

template
```c++
using P = pair<int, int>;
// sort(A.begin(), A.end(), cmp)
bool cmp(P a, P b) { return a.second < b.second; }
#ifdef DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
#else
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#endif
const ll INF = 1LL << 60;
const int MAX_ITEM = 10e4+10; // 10^5
ll dp[MAX_ITEM] = {0};
```

## 組み合わせ

- n種類からk種類を取る組み合わせは comb(n,k)
- n種類で作る全ての組み合わせの和は 2^n
  - n が 10^9 とかの場合、O(N) だと TLE するので 「繰り返し二乗法」を使う。

### 階乗の計算
n! とかで使う
```c++
int factorial(int n) {
  return (n == 1) ? 1 : n * factorial(n - 1);
}
factorial(5) // 5! = 120
```

### 順列 permutation
NaN

### 組み合わせ Combination
- 組み合わせの個数 nCr を求める

nCr = n*(n-1)*...*(n-r+1) / 1*2*...*r

nCr mod M = n*(n-1)*...*(n-r+1) mod M * pow(r, mod-2) mod M

```c++
mint nCr(int n, int r) {
  mint x = 1, y = 1;
  rep(i, 0, r) {
    x *= n-i;
    y *= i+1;
  }
  return x / y;
}
nCr(4, 2); // 6
```

この方法の計算量は O(N) なので、min(r, n-r) が 10^5 くらいなら間に合うがそれ以上だと間に合わない。
逆に言えば、n が 10^9 くらいでも min(r, n-r) が十分に小さければ間に合う -> ABC156-D

- nCr を高速に計算する

n が 300001 よりも小さく、 nCr を O(1) で計算したい場合にはこちらがおすすめ。

```c++
vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

// comb(n,k) を使う前に、n! と k!^{mod-2} を準備しておく。
// 制約: 0 < n,k < 300001
void nCr_init(int mod) { 
  fac[0] = 1;
  ifac[0] = 1;
  rep(i, 0, 300000) {
    fac[i+1] = fac[i] * (i+1) % mod;
    ifac[i+1] = ifac[i] * pow(i+1, mod-2, mod) % mod;
  }
}
// フェルマーの小定理を応用して Combination 計算を行う
// nCr(n,k) = n! * k!^{M-2} * (n-k)!^{M-2} 
int nCr(int n, int k, int mod) {
  if (n == 0 && k == 0) return 1;
  if (n < k || n < 0) return 0;
  // comb(n,k) = n! * k!^{M-2} * (n-k)!^{M-2} 
  return (fac[n] * ifac[k] % mod) * ifac[n-k] % mod;
}

int mod = 1000000007;
nCr_init(mod);
nCr(4, 2, mod); // 6
```

### 二項係数の和
n種類で作る全ての組み合わせの和は 2^n となる
例えば n=4 のとき、
```
//c(4,0) + c(4,1) + c(4,2) + c(4,3) + c(4,4)
//= 1+4+6+4+1
//= 2^4

pow(2, 4);
```

### 繰り返し二乗法

- 2^n mod 10^9+7 などを計算するとき、nが巨大で計算量が大きくなる場合に有効
- 考え方としては、2^10 を (2^2)^5 とするように乗数を 2 で割って再帰的に計算をしてく
- 例: 2^1000000000 mod 1000000007 
- → (((((((2^2)^2)^2)^2)^2)^2)^2)^2)^2)^2 ...

```c++
mint pow_(int base, int n) {
  if (n == 0) return 1;
  mint x = pow_(base, n/base);
  x *= x;
  if (n%base == 1) x *= mint(base);
  return x;
}
pow(2, 1000000000); // 2^(10^9) mod 10^9+7
```

## Union-Find

根と根をつないで木にするやつ

```c++
struct UnionFind {
  vector<int> par;
  UnionFind(int N): par(N) { rep(i, 0, N) par[i] = i; }
  int root(int x) { if (par[x] == x) return x; return par[x] = root(par[x]); }
  void unite(int x, int y) { int rx = root(x); int ry = root(y); if (rx == ry) return; par[rx] = ry; }
  bool same(int x, int y) { return root(x) == root(y); }
};

int main() {
  // input
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);

  // calculation
  int p, a, b;
  rep(i, 0, q) {
    cin >> p >> a >> b;
    if (p == 0) {
      // 連結
      uf.unite(a,b);
    } else {
      // 判定
      cout << (uf.same(a,b) ? "Yes" : "No") << endl; 
    }
  }
}
```