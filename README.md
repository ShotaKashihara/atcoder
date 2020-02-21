# atcoder

## Algorithm
- 二分探索
  - ABC077 C
  - ARC037 C
- 桁DP
  - ABC155 E

## C++

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
#define rep(i,a,b) for(int i=a;i<b;i++)
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

