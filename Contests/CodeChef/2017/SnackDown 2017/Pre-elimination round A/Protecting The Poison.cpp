#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

struct interval {
	int in, out;
	interval() {}
	interval(int _in, int _out) : in(_in), out(_out) {}
	bool operator < (const interval other) const {
		if (in != other.in) return in < other.in;
		return out > other.out;
	}
};

bool intersec(interval a, interval b) { return a.out >= b.in && a.in <= b.out; }

interval center;

int min_interval_covering(vector<interval> &v) {
	sort(v.begin(), v.end());
	if (v.size() == 0 || v[0].in > center.in) return -1;
	int target = 1, curr = 0;
	for (int it = 1, nxt; v[curr].out != center.out && it < v.size(); curr = nxt) {
		nxt = -1;
		while (it < v.size()) {
			if (v[it].in > v[curr].out + 1) break;
			if (nxt == -1 || v[it].out > v[nxt].out) nxt = it;
			it++;
		}
		if (nxt == -1) return -1;
		target++;
	}
	if (v[curr].out != center.out) return -1;
	return target;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k, m; cin >> n >> k >> m;
		center = interval((n - k) / 2 + 1, (n - k) / 2 + k);
		vector<interval> hor, ver;
		while (m--) {
			int ri, ci, rf, cf; cin >> ri >> ci >> rf >> cf;
			if (intersec(interval(ci, cf), interval((n - k) / 2 + 1, (n - k) / 2 + k)))
				hor.push_back(interval(max((n - k) / 2 + 1, ci), min((n - k) / 2 + k, cf)));
			if (intersec(interval(ri, rf), interval((n - k) / 2 + 1, (n - k) / 2 + k)))
				ver.push_back(interval(max((n - k) / 2 + 1, ri), min((n - k) / 2 + k, rf)));
		}
		int ans = 0, ans_hor, ans_ver;
		ans += ans_hor = min_interval_covering(hor);
		ans += ans_ver = min_interval_covering(ver);
		if (ans_hor == -1 || ans_ver == -1)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}