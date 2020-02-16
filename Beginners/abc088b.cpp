#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
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
  int n; cin >> n;

  vector<int> a;
  rep(i,n) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.rbegin(), a.rend());

  var turn = "Alice";
  int alice = 0;
  int bob = 0;
  for (auto &aa : a) {
    if (turn == "Alice") {
      turn = "Bob";
      alice += aa;
    } else {
      turn = "Alice";
      bob += aa;
    }
  }

  cout << alice - bob << endl;
  return 0;
}
