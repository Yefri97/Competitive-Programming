/*
ID: yefri.g1
PROG: skidesign
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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin ("skidesign.in");
	ofstream fout ("skidesign.out");
	int n; fin >> n;
	vi hills(n);
	fori(i, 0, n)
		fin >> hills[i];
	int ans = oo;
	fori(i, 0, 100 - 17 + 1) {
		int acc = 0;
		fori(j, 0, n) {
			if (hills[j] < i)
				acc += sq(i - hills[j]);
			if (hills[j] > i + 17)
				acc += sq(hills[j] - (i + 17));
		}
		ans = min(ans, acc);
	}
	fout << ans << endl;
	return 0;
}