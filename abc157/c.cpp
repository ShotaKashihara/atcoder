#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  int s[m], c[m];
  rep(i,0,m) {
    cin >> s[i] >> c[i];
  }

  // n桁まで求める
  // 3 なので 0~999 -> 全探索可能


  
  // s[] の中で重複がある && c[]が違う数字 → -1
  
  int ans_i = 0;

  rep(i,0,1000) {
    int _1, _2, _3;

    _1 = i % 10;
    _2 = (i % 100 - _1) / 10;
    _3 = (i % 1000 - _1 - _2) / 100;

    if (n == 3 && _3 == 0) {
      continue;
    }
    if (n == 2 && _3 != 0) {
      continue;
    }
    if (n == 1 && _3 != 0) {
      continue;
    }
    if (n == 1 && _2 != 0) {
      continue;
    }

    bool ans2 = true;
    rep(j, 0, m) {
      if (s[j] > n) {
        ans2 = false;
      }


      if (s[j] == 1 && _3 != c[j]) {
        ans2 = false;
      }
      else if (s[j] == 2 && _2 != c[j]) {
        ans2 = false;
      }
      else if (s[j] == 3 && _1 != c[j]) {
        ans2 = false;
      }
    }
    if (ans2) {
      ans_i = i;
      break;
    }
  }

  if (ans_i > 0) {
    cout << ans_i << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
