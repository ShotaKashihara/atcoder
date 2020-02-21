#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,a,b) for(int i=a;i<b;i++)
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

int main() {
  int target = 51;

  sort(all(a));
  auto l_i = lower_bound(all(a), target);
  auto u_i = upper_bound(all(a), target);

  cout << "target: " << target << endl;
  cout << "array.size(): " << a.size() << endl;
  cout << "array: ";
  rep(i,0,a.size()) cout << a[i] << ",";
  cout << endl;
  
  cout << "(*lower_bound)target以上の最初の値: " << *l_i << endl;
  cout << "(*upper_bound)targetより大きいの最初の値: " << *u_i << endl;

  cout << "(lower_bound)target未満の個数:" << l_i - a.begin() << endl;
  cout << "(lower_bound)target以上の個数:" << a.end() - l_i << endl;
  cout << "(upper_bound)target以下の個数:" << a.end() - u_i << endl;
  cout << "(upper_bound)targetより大きい個数:" << u_i - a.begin() << endl;

  cout << "(upper - lower)targetと同値の個数:" << u_i - l_i << endl;
}
