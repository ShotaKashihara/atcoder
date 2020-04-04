#include <bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define SZ(x) ((int)(x).size())
#define bit(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

// ATC001A: https://atcoder.jp/contests/atc001/tasks/dfs_a
// 迷路フィールド
vector<vector<int>> a(510, vector<int>(510));

int dw[4] = { 1, 0, -1, 0 };
int dh[4] = { 0, 1, 0, -1 };
enum { Barrier, Nothing, Fill, Start, Goal, Failure = 100 };
void dfs(int h, int w) {
  if (h < 0 || w < 0) return;
  if (a.at(h).at(w) == Barrier) return; // (w,h) が壁
  if (a.at(h).at(w) == Fill) return; // (w,h) は到達済み

  a.at(h).at(w) = Fill; // 到達

  rep(i, 4) dfs(h + dh[i], w + dw[i]); // 4方向を試す
}

int main() {
  // int h,w;
  // cin >> h >> w; // (w,h) 
  // P s,g; // スタート地点, ゴール地点
  // rep(_h,h) {
  //   string line; // "s..###" みたいな文字列
  //   cin >> line;
  //   rep(_w,w) {
  //     if (line[_w] != '#') a.at(_h).at(_w) = Nothing; // 通れる道をマーキング
  //     if (line[_w] == 's') s = P(_h,_w); // スタート地点
  //     if (line[_w] == 'g') g = P(_h,_w); // ゴール地点
  //   }
  // }

  // dfs(s.first, s.second);

  // if (a.at(g.first).at(g.second) == Fill) cout << "Yes" << endl; // ゴール地点が "Fill" なら Yes
  // else cout << "No" << endl;

  rep(i, 1, 161) {
    cout << "acc new abc" << setw(3) << setfill('0') << i << endl;
  }

  return 0;
}
