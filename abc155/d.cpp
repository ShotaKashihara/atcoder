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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a;
  rep(i,n) {
    ll aa; cin >> aa;
    a.push_back(aa);
  }


  // ペア
  











  // int n,k;
  // cin >> n >> k;
  // int h[n];
  // rep(i,n) cin >> h[i];

  // // 最小化問題なので INF or 0 で埋める
  // rep(i,MAX_ITEM) {
  //   dp[i] = INF;
  // }
   
  // // 初期値は 0 or INF
  // dp[0] = 0;

  // // 足場だけ回す
  // rep(i,n-1) {
  //   // 足場i+j の値は 足場iのコストに abs(h[i] - h[i+j]) を足した数
  //   rep(j,k+1) {
  //     if (j == 0) continue;
  //     chmin(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
  //   }
  // }
  
  // cout << dp[n-1] << endl;
  return 0;
}
