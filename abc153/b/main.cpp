#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h,n;
  cin >> h >> n;
  // vector<int> a(n);
  int sum = 0;
  rep(i,n) {
    int a; cin >> a;
    sum += a;
  }
  cout << (h > sum ? "No" : "Yes") << endl;

  return 0;
}
