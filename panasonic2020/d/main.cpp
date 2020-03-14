#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<(a+n);i++)
#define var auto
using namespace std;
using ll = long long;

// input: "a"
// output: ["a", "b"]
char[] ch(char n) {
  char c = 'a' + n;
  cout << c << endl;
}

// input: ["a"], 2
// output: ["aa", "ab"], 1
// input: ["aa", "ab"], 1
// output: ["aaa", "aab", "aba", "abb", "abc"], 1
char hoge(char a[]) {
  vector<string> aa;
  for (auto &array : a) {
    aa.push_back()
  }
}

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "a" << endl;
  } else if (n == 2) {
    rep(i, 0, n) {
      // "a" は確定
      // 次の文字は 前の文字が "a" なら "a" と "b" を出力する
      cout << "a" << "a" << endl;
      cout << "a" << "b" << endl;
    }
  }

  return 0;
}
