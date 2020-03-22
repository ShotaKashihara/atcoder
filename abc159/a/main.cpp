#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  // 偶数x偶数のパターン数
  int guusuu = ((n>1) ? (n*(n-1))/2 : 0);
  // 奇数x奇数のパターン数
  int kisuu = ((m>1) ? (m*(m-1))/2 : 0);
  cout << guusuu + kisuu << endl;

  return 0;
}
