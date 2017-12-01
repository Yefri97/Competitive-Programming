/*
ID: yefri.g1
PROG: combo
LANG: C++
*/
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int check(vi& v, int a, int b, int c, int n) {
	int ok = 1;
	ok &= mod(v[0] - a, n) < 3 || mod(a - v[0], n) < 3;
	ok &= mod(v[1] - b, n) < 3 || mod(b - v[1], n) < 3;
	ok &= mod(v[2] - c, n) < 3 || mod(c - v[2], n) < 3;
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin ("combo.in");
  ofstream fout ("combo.out");
  int n; fin >> n;
  vi farmer(3), master(3);
  fori(i, 0, 3)
  	fin >> farmer[i];
  fori(i, 0, 3)
  	fin >> master[i];
  int ans = 0;
  fori(a, 0, n)
  	fori(b, 0, n)
  		fori(c, 0, n)
  			ans += check(farmer, a, b, c, n) | check(master, a, b, c, n);
	fout << ans << endl;
	return 0;
}