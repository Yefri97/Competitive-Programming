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
typedef pair<string, string> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int oo = 1e9;

vector<string> solver(vvii &v, vi &vid) {
	int n = v.size(), m = vid.size();
	fori(i, 0, 24) {
		vector<string> ans;
		fori(j, 0, m) {
			int id = vid[j], l = v[id].size();
			fori(k, 0, l) {
				string schedule = v[id][k].first, room = v[id][k].second;
				if (schedule[i] == '.') {
					ans.push_back(room);
					break;
				}
			}
		}
		if (ans.size() == m)
			return ans;
	}
	return vector<string>();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vvii v(n);
	map<string, int> mapper;
	fori(i, 0, n) {
		string city; cin >> city;
		mapper[city] = i;
		int k; cin >> k;
		while (k--) {
			string schedule, room; cin >> schedule >> room;
			v[i].push_back(ii(schedule, room));
		}
	}
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		vi vid;
		while (k--) {
			string s; cin >> s;
			vid.push_back(mapper[s]);
		}
		vector<string> ans = solver(v, vid);
		if (ans.size() == 0)
			cout << "No" << endl;
		else {
			cout << "Yes";
			fori(i, 0, ans.size())
				cout << " " << ans[i];
			cout << endl;
		}
	}
	return 0;
}