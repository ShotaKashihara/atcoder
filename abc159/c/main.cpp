#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  long double l;
  cin >> l;

  long double hen = l/3.0;

  cout << fixed << setprecision(12) << hen*hen*hen << endl;

  return 0;
}
