#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
  int b = 200000;
  int a = 199900;
  ll ans = 0;
  for (auto &bb : b) {
    ans += (bb*(bb-1))/2;
  }
}
