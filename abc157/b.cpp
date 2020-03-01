#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int a[3][3];
  cin >> a[0][0] >> a[0][1] >> a[0][2];
  cin >> a[1][0] >> a[1][1] >> a[1][2];
  cin >> a[2][0] >> a[2][1] >> a[2][2];
  int n;
  cin >> n;
  vector<int> b;
  rep(i,0,n) {
    int bb; cin >> bb;
    b.push_back(bb);
  }

  bool ans = false;
  // 縦のビンゴ
  rep(i,0,3) {
    if (find(b.begin(), b.end(), a[0][i]) != b.end() 
      && find(b.begin(), b.end(), a[1][i]) != b.end() 
      && find(b.begin(), b.end(), a[2][i]) != b.end()) {
        ans = true;
        break;
    }
  }

  // 横のビンゴ
  rep(i,0,3) {
    if (find(b.begin(), b.end(), a[i][0]) != b.end() 
      && find(b.begin(), b.end(), a[i][1]) != b.end() 
      && find(b.begin(), b.end(), a[i][2]) != b.end()) {
        ans = true;
        break;
    }
  }

  // 斜めのビンゴ
  
  if (find(b.begin(), b.end(), a[0][0]) != b.end() 
    && find(b.begin(), b.end(), a[1][1]) != b.end() 
    && find(b.begin(), b.end(), a[2][2]) != b.end()) {
      ans = true;
  }
  if (find(b.begin(), b.end(), a[0][2]) != b.end() 
    && find(b.begin(), b.end(), a[1][1]) != b.end() 
    && find(b.begin(), b.end(), a[2][0]) != b.end()) {
      ans = true;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
