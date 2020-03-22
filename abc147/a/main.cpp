#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a1,a2,a3;
  cin >> a1 >> a2 >> a3;
  cout << ((a1+a2+a3 >= 22) ? "bust" : "win") << endl;
  return 0;
}
