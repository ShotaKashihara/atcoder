#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
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

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> A(m);
  rep(i,m) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end(), [](P a, P b){
    return a.second < b.second; // 終端ソート
  });

  // 串に刺したときの始点を覚えておく
  int res = 0;
  int point = 0;
  rep(i,m) {
    if (point <= A[i].first) {
      point = A[i].second;
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}
