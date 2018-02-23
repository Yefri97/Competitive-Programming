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
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n; fin >> n;
	vi v(n);
	fori(i, 0, n)
		fin >> v[i];
	sort(v.begin(), v.end());
	int ans = -1;
	fori(i, 0, n) {
		int pos_upper = upper_bound(v.begin(), v.end(), 2 * v[i]) - v.begin();
		int val = pos_upper - i;
		ans = max(ans, val);
	}
	fout << n - ans << endl;
	return 0;
}