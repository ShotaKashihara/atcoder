#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a[i];
  set<int> s(a.begin(), a.end());
  if (a.size() == s.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}
