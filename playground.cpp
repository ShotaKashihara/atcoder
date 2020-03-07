#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
using ll = long long;

int main() {
  int n = 10;

  // GCC 5.4.1
  vector<int> v(n);
  cout << v[n] << endl; // 132033

  // GCC 9.2.0
  vector<int> v(n);
  cout << v[n] << endl; // 0
}

