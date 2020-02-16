#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define var auto
using namespace std;
using ll = long long;
using P = pair<int, int>;
// sort(A.begin(), A.end(), cmp)
bool cmp(P a, P b) { return a.second < b.second; }
#ifdef DEBUG
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; cout << a << endl; return 1; } cout << a << endl; return 0; }
#else
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#endif
const ll INF = 1LL << 60;
const int MAX_ITEM = 10e4+10; // 10^5
ll dp[MAX_ITEM] = {0};

map<int, vector<int>> lis;

int main() {
  int n,m;
  cin >> n >> m;
  int a[n],b[n]; rep(i,n) {
    int a,b;
    cin >> a >> b;
    lis[a].push_back(b); // 重さa 報酬b の仕事
  }

  // 0→M日間の報酬合計
  ll res = 0;
  priority_queue<int> q; // 優先度付きキュー
  rep(i,m+1) { // 1...m
    if(0 == i) continue;
    // i日後の報酬がもらえるバイトをキューに入れる
    for (auto &vv : lis[i]) {
      q.push(vv);
    }
    // i日目
    if (q.size() == 0) continue;

    res += q.top();
    q.pop();
  }

  cout << res << endl;
  return 0;
}
