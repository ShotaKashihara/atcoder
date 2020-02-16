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

ll y;
ll n;
int yukichi = 0;
int higuchi = 0;
int noguchi = 0;

int ndiff() {
  return yukichi + higuchi + noguchi - n;
}

bool itsAnswer(int yn, int hn, int nn) {
  if (yn*10000+hn*5000+nn*1000 == y) {
    return (n - yn - hn - nn) == 0;
  }
  return false;
}

int main() {
  
  cin >> n >> y;

  int m_y = min(y / 10000, n); // 10^3
  int m_h = min(y / 5000, n);
  // int m_n = min(y / 1000, n); これ無駄

  rep(yy, m_y+1) {
    rep(hh, m_h+1) {
      int nn = n - yy - hh;
      if (nn < 0) continue;
      if (itsAnswer(yy, hh, nn)) {
        cout << yy << " " << hh << " " << nn << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
