#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	ifstream fin("input.txt");    // File Input
  ofstream fout("output.txt");  // File Output
	int n, m; fin >> n >> m;
	int x = min(n, m);
	if (n - x > 0) {
		fori(i, 0, x)
			fout << "BG";
	} else {
		fori(i, 0, x)
			fout << "GB";
	}
	fori(i, 0, n - x)
		fout << "B";
	fori(i, 0, m - x)
		fout << "G";
	fout << endl;
	return 0;
}