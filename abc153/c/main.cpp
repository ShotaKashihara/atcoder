#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> h(200100);

int main() {
  int n,k;
  cin >> n >> k;
  rep(i,200100) h[i] = INFINITY;
  rep(i,n) cin >> h[i];

  sort(h.begin(), h.end());

  ll sum = 0;
  rep(i,n-k) {
    sum += h[i];
  }
  cout << sum << endl;

  return 0;
}
