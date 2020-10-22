#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int m, n; cin >> m >> n;
	set<int> dict;
	dict.insert(0);
	dict.insert(m);
	map<int, int> cnt;
	cnt[m]++;
	while (n--) {
		int x; cin >> x;
		auto it = dict.upper_bound(x);
		int up = *it; it--;
		int dw = *it;
		dict.insert(x);
		cnt[up - dw]--;
		if (cnt[up - dw] == 0)
			cnt.erase(up - dw);
		cnt[up - x]++;
		cnt[x - dw]++;
		auto it2 = cnt.end(); it2--;
		cout << it2->first << " ";
	}
	cout << endl;
	return 0;
}
