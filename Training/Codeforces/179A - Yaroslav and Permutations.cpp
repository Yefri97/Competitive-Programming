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
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<int, int> mapper;
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		mapper[x]++;
	}
	bool ans = true;
	for (map<int, int>::iterator it = mapper.begin(); it != mapper.end(); it++)
		if ((int)(it->second) > (n + 1) / 2) ans = false;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}