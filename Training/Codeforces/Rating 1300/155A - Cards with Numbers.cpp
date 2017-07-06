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
	map<int, vi> mapper;
	int n; fin >> n;
	fori(i, 0, 2 * n) {
		int x; fin >> x;
		mapper[x].push_back(i);
	}
	bool ans = true;
	for (map<int, vi>::iterator it = mapper.begin(); it != mapper.end(); it++) {
		vi v = it->second;
		if (v.size() % 2) ans = false;
	}
	if (ans) {
		for (map<int, vi>::iterator it = mapper.begin(); it != mapper.end(); it++) {
			vi v = it->second;
			fori(i, 0, v.size() / 2)
				fout << v[2 * i] + 1 << " " << v[2 * i + 1] + 1 << endl;
		}	
	} else {
		fout << -1 << endl;
	}
	return 0;
}