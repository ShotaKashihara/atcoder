#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> a(200010);
vector<ll> b(200010);

int main() {
  int n;
  cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];

  // とりあえず、現状で選び出すパターン数を求める
  // 1. 数字A が N個あるかをまとめる
  rep(i,n){
    b[a[i]]++;
  }
  ll ans = 0;
  for (auto &bb : b) {
    ans += (bb*(bb-1))/2;
  }

  rep(i,n) {
    // i番目を除いたときに、いくつ減るかを見る
    // e.g. 1=3個、 2=2個、 3=5個のとき
    // i番目が 1 なら、 パターンが 3パターン→ 1パターン なので 2減る
    // i番目が 2 なら、 パターンが 1パターン→ 0パターン なので 1減る
    // i番目が 3 なら、 パターンが 10パターン→ 6パターン なので 4減る

    int count = b[a[i]];
    int new_c = count -1;
    ll minus = ((count*(count-1)) / 2) - (new_c*(new_c-1)) / 2;
    if (new_c == 0) {
      minus = 0;
    }

    cout << ans-minus << endl;
  }

  return 0;
}
