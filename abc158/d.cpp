#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  int q;
  cin >> q;
  cin.ignore();

  int ans = 0;

  bool isrev = false;
  // vector<string> a1;
  // vector<string> a2;
  string a1 = "";
  string a2 = "";
  rep(i, 0, q) {
    string s1;    
    getline(cin, s1);

    if (s1[0] == '1') {
      isrev = !isrev;
      // reverse(s.begin(), s.end());
    } else {
      if (s1[2] == '1') {
        if (isrev) a2 = a2 + s1[4];
        else a1 = a1 + s1[4];
        // s = s1[4] + s;
      } else {
        if (isrev) a1 = a1 + s1[4];
        else a2 = a2 + s1[4];
        // s = s + s1[4];
      }
    }
  }

  if (isrev) {
    reverse(s.begin(), s.end());
    reverse(a2.begin(), a2.end());
    s = a2 + s + a1;
  } else {
    reverse(a1.begin(), a1.end());
    s = a1 + s + a2;
  }
  cout << s << endl;
  return 0;
}
