#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int get(multiset<int> &d, int x) {
	int ans = 0;
	if (x) {
		auto it = d.end(); it--;
		ans += *(it);
	} else {
		auto it = d.begin();
		ans += *(it); it++;
		if (it == d.end()) it--;
		ans += *(it);
	}
	return ans;
}

void remove(multiset<int> &d, int x) {
	auto it = d.find(x);
	d.erase(it);
}

void add(multiset<int> &d, int x) {
	d.insert(x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	multiset<int> dict;
	add(dict, v[0]);
	ll ans = 0;
	for (int l = 0, r = 0; l < n; l++) {
		while (r < n) {
			int sum = get(dict, 0);
			int largest = get(dict, 1);
			if (sum < largest) break;
			r++;
			add(dict, v[r]);
		}
		remove(dict, v[l]);
		ans += (r - l);
	}
	cout << ans << endl;
	return 0;
}
