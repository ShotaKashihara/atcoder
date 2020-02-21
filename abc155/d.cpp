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

ll p[MAX_ITEM];
ll m[MAX_ITEM];

int main() {
  int n,k;
  cin >> n >> k;
  
  rep(i,n) {
    ll c; cin >> c;
    if (c > 0) {
      
    }
  }

  // 一周目
  // a[0] * [1] [2] [3]
  // a[1] * [2] [3]
  // a[2] * [3]

  // 間に合わない!!!

  // 正x負 負x正 が最小



  return 0;
}
