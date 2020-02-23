#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)
 
#define int long long
//using ll = long long;
using P = pair<int,int>;
 
ostream &operator<<(ostream &os,const P &p){ return os << "(" << p.first << "," << p.second << ")"; }
 
template<class T> T &chmin(T &a,const T &b){ return a = min(a,b); }
template<class T> T &chmax(T &a,const T &b){ return a = max(a,b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
 
template<long long mod = 1000000007>
struct modint{
	long long a;
 
	modint() : a(0){}
	modint(long long t){
		a = t % mod;
		if(a < 0) a += mod;
	}
 
	operator long long() const{ return a; }
 
	bool operator==(const modint &x) const{ return a == x.a; }
	bool operator!=(const modint &x) const{ return a != x.a; }
 
	modint operator-() const{ return modint(a ? (mod - a) : 0); }
	modint operator~() const{ return pow(mod - 2); }
 
	modint operator+(const modint &x) const{ return modint(*this) += x; }
	modint operator-(const modint &x) const{ return modint(*this) -= x; }
	modint operator*(const modint &x) const{ return modint(*this) *= x; }
	modint operator/(const modint &x) const{ return modint(*this) /= x; }
 
	modint &operator+=(const modint &x){
		a += x.a;
		if(a >= mod) a -= mod;
		return *this;
	}
	modint &operator-=(const modint &x){
		a -= x.a;
		if(a < 0) a += mod;
		return *this;
	}
	modint &operator*=(const modint &x){
		a = a * x.a % mod;
		return *this;
	}
	modint &operator/=(const modint &x){
		a = a * (~x).a % mod; 
		return *this;
	}
 
	friend ostream &operator<<(ostream &os,const modint &x){
		return os << x.a;
	}
	friend istream &operator>>(istream &is,modint &x){
		long long t;
		is >> t;
		x = modint(t);
		return is;
	}
 
	modint pow(long long x) const{
		modint ret = 1,tmp = a;
		for(;x;tmp *= tmp,x >>= 1){
			if(x & 1) ret *= tmp;
		}
		return ret;
	}
};
 
modint<> nCr(int n,int r){
	modint<> ans = 1;
	for(int i = 1;i <= r;i++) ans = ans * modint<>(n - i + 1) / modint<>(i);
	return ans;
}
 
signed main(){
	// int n,a,b;

  int n = 1000000000;
  int a = 141421;
  int b = 173205;
  cout << modint<>(2).pow(n) << endl;
  cout << nCr(n,a) << endl;
  cout << nCr(n,b) << endl;

	cin >> n >> a >> b;
	cout << modint<>(2).pow(n) - nCr(n,a) - nCr(n,b) - modint<>(1) << endl;
}