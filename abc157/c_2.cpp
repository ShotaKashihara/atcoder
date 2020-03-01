#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> s, c;
  rep(i,0,m) {
    int ss, cc;
    cin >> ss >> cc;
    s.push_back(ss);
    c.push_back(cc);
  }

  // s が重複しているかつ c が異なるものが2つ以上
  int _1 = -1;
  int _2 = -1;
  int _3 = -1;
  bool ans = true;
  rep(i,0,m) {
    if (s[i] == 1) {
      if (_1 == -1) {
        _1 = c[i];
      } else if (_1 != c[i]) {
        ans = false;
      }
    }
    if (s[i] == 2) {
      if (_2 == -1) {
        _2 = c[i];
      } else if (_2 != c[i]) {
        ans = false;
      }
    }
    if (s[i] == 3) {
      if (_3 == -1) {
        _3 = c[i];
      } else if (_3 != c[i]) {
        ans = false;
      }
    }
  }

  if (n > 1 && _1 == 0) {
    ans = false;
  }

  if (_1 == -1) {
    _1 = 0;
  }
  if (_2 == -1) {
    _2 = 0;
  }
  if (_3 == -1) {
    _3 = 0;
  }

  if (ans) {
    if (n == 1) {
      cout << _1 << endl;
    } 
    if (n == 2) {
      if ((_1*10 + _2) >= 10) {
        cout << _1*10 + _2 << endl;
      } else {
        cout << _1*10 + _2 + 10 << endl;
      }
    }
    if (n == 3) {
      if ((_1*100 + _2*10 + _3) >= 100) {
        cout << _1*100 + _2*10 + _3 << endl;
      } else {
        cout << _1*100 + _2*10 + _3 + 100 << endl;
      }
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
