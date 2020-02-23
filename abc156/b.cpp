#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define var auto
using namespace std;
using ll = long long;

int main() {
  ll n;
  int k;
  cin >> n >> k;

  vector<int> a;
  while (n >= k) {
    int s = n % k; // 11 % 2 = 1
    a.push_back(s);
    n = n / k; // 11 / 2 = 5
  }

  cout << a.size() + 1 << endl;

  return 0;
}
