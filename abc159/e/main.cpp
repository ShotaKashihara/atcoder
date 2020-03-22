#include <bits/stdc++.h>
// e.g. sort(all(a), [](int a1, int a2) { return a1 < a2; });
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H,W,K;
  cin >> H >> W >> K;
  
  // 入力: H × W のグリッド
  vector<vector<int> > a(H, vector<int>(W));
  rep(i,H) {
    string s;
    cin >> s;
    rep(j,W) {
      int aa = s[j] - '0';
      a[i][j] = aa;
    }
  }
  // 二次元累積和
  vector<vector<int> > s(H+1, vector<int>(W+1, 0));
  for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j)
          s[i+1][j+1] = s[i][j+1] + s[i+1][j] - s[i][j] + a[i][j];

  // // [x1, x2) x [y1, y2) の和
  // int x1,x2,y1,y2 = 0;
  // int ans = s[x2][y2] - s[x1][y2] - s[x2][y1] - s[x1][y1];

  // あとは全探索
  bool ng = true;
  bool ans = INFINITY;

  // 割らない可能性も考える
  int x1 = 0, y1 = 0;
  int x2 = H-1, y2 = W-1;
  int aaa = s[x2][y2] - s[x1][y2] - s[x2][y1] - s[x1][y1];
  if (aaa <= K) {
    ng = false;
    ans = 0;
  }

  // bit 全探索
  // int n = (W-1)*(H-1);
  while(ng) {
    // ans 分割するパターンを全網羅する
    rep(w_bit, 1<<(W-1)) {
      rep(h_bit, 1<<(H-1)) {
        // K < sum な部分があるか確認
        // 分割数を求める
        // 縦の分割数:
        
      }
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}
