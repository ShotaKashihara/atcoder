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

string d1 = "dream";
string d2 = "dreamer";
string e1 = "erase";
string e2 = "eraser";

// ends_with("abc", "bc") == true
bool ends_with(const std::string& s, const std::string& suffix) {
   if (s.size() < suffix.size()) return false;
   return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}

int main() {
  string s;
  cin >> s;

  // s の末尾が m,mer,se,ser の4通りを考える
  
  while(s.size() > 0) {
    if (ends_with(s, d1)) {
      s.erase(s.size() - d1.size());
    } else if (ends_with(s, d2)) {
      s.erase(s.size() - d2.size());
    } else if (ends_with(s, e1)) {
      s.erase(s.size() - e1.size());
    } else if (ends_with(s, e2)) {
      s.erase(s.size() - e2.size());
    } else {
      break;
    }
  }

  if (s.size() == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
