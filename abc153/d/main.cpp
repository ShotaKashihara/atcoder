#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll h;
  cin >> h;

  ll bunretsu = 1;
  ll attack = 0;
  while (true) {
    if (h < 2) {
      attack += bunretsu;
      break;
    } else {
      h = h/2;
      attack += bunretsu;
      bunretsu *= 2;
    }
  }
  
  cout << attack << endl;
  return 0;
}

// 1 -> 1
// 2 -> 1 + 2
// 3 -> 1 + 2
// 4 -> 1 + 2 + 4
// 5 -> 1 + 2 + 4
// 6 -> 1 + 2 + 4
// 7 -> 1 + 2 + 4
// 8 -> 1 + 2 + 4 + 8
