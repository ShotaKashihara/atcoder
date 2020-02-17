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
  cin >> n;
  vector<int> a;
  rep(i,n) {
    int aa;
    cin >> aa;
    a.push_back(aa);
  }

  bool res = all_of(a.begin(), a.end(), [](int aa) {
    return (aa % 2 == 1 || (aa % 3 == 0 || aa % 5 == 0));
  });

  if (res) {
    cout << "APPROVED" << endl;
  } else {
    cout << "DENIED" << endl;
  }
  return 0;
}
