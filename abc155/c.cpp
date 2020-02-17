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
  // vector<string> s;
  map<string, int> m;
  rep(i,n) {
    string ss;
    cin >> ss;
    // s.push_back(ss);
    m[ss] += 1;
  }

  // 最大値を出す
  int max = 0;
  vector<string> max_s;
  for (auto &mm : m) {
    if (mm.second > max) {
      max = mm.second;
      max_s = {mm.first};
    } else if (mm.second == max) {
      max_s.push_back(mm.first);
    }
  }

  sort(max_s.begin(), max_s.end());

  for (auto &ss: max_s) {
    cout << ss << endl;
  }
  
  return 0;
}
