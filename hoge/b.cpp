#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll takahashi, aoki, k;
  cin >> takahashi >> aoki >> k;
  aoki = max(aoki - max(k - takahashi, 0ll), 0ll);
  takahashi = max(takahashi - k, 0ll);
  cout << takahashi << " " << aoki << endl;
}
