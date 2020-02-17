#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
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

int main() {
  
  vector<int> v = { 10,20,30,40,50 };
  array<int, 5> a = { 10, 20, 30, 40, 50};
  // cout << all_of(arr.begin(), arr.end(), [](int i) {
  //   return i % 2 == 0;
  // }) << endl;

  // for_each(arr.begin(), arr.end(), [](int i) {
  //   cout << i << endl;
  // }); 

  
  // var f = find(arr.begin(), arr.end(), 1);

  // sort(a.rbegin(), a.rend());
  for_each(a.begin(), a.end(), [](int aa) {
    cout << aa << endl;
  });

  return 0;
}
