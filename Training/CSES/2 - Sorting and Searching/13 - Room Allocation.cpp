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
	vector<ii> ev;
	fori(i, 1, n + 1) {
		int a, b; cin >> a >> b;
		ev.push_back(ii(a, -i));
		ev.push_back(ii(b, +i));
	}
	sort(all(ev));
	int mx = 1;
	vi ans(n), rooms;
	for (ii e : ev) {
		int id = abs(e.second) - 1;
		if (e.second > 0) {
			rooms.push_back(ans[id]);
		} else {
			if (SZ(rooms) == 0)
				rooms.push_back(mx++);
			ans[id] = rooms.back();
			rooms.pop_back();
		}
	}
	cout << mx - 1 << endl;
	fori(i, 0, n)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
