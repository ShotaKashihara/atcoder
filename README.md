# atcoder

## Algorithm
- 二分探索
  - ABC077 C
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
// asc sort
sort(A.begin(), A.end());

// desc sort
sort(A.rbegin(), A.rend());

// compあり sort
sort(a.begin(), a.end(), [](int a1, int a2) {
  return a1 > a2;
});
```
