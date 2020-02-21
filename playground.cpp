#include <iostream>
#include <vector>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

// index が条件を満たすかどうか
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(int key) {

  int ng = 20; // 初期値の左端
  int ok = 36; // 初期値の右端

  // 両端にある、leftとrightの差が 1 になるまでループする

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (isOK(mid, key)) ok = mid; // isOK を満たしていたら、mid は ok
    else ng = mid; // isOK を満たしていなければ、mid は ng
  }
}

int main() {
    cout << binary_search(51) << endl; // a[3] = 51 (さっきは 4 を返したが今回は「最小の index」なので 3)
    cout << binary_search(1) << endl; // a[0] = 1
    cout << binary_search(910) << endl; // a[9] = 910

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10 (場外)
}