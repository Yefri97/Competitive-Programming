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
	int n; cin >> n;
	vector<ii> events;
	fori(i, 1, n + 1) {
		int a, b; cin >> a >> b;
		events.push_back(ii(a, +i));
		events.push_back(ii(b, -i));
	}
	sort(all(events));
	set<int> seen;
	int ans = 0;
	for (auto e : events) {
		if (e.second < 0) {
			if (seen.count(-e.second)) {
				ans++;
				seen.clear();
			}
		} else {
			seen.insert(e.second);
		}
	}
	cout << ans << endl;
	return 0;
}
