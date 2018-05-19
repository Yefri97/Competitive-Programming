#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string names[] = {"Kuro", "Shiro", "Katie"};

int f(string s, int k) {
	int n = s.size();
	map<char, int> counter;
	for (char c : s)
		counter[c]++;
	if (k == 1 && counter.size() == 1) return n - 1;
	int ans = 0;
	for (auto c : counter) {
		int d = c.second;
		ans = max(ans, min(d + k, n));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> vs(3);
	fori(i, 0, 3)
		cin >> vs[i];
	vector<ii> v(3);
	fori(i, 0, 3)
		v[i] = ii(f(vs[i], n), i);
	sort(v.begin(), v.end());
	if (v[1].first == v[2].first)
		cout << "Draw" << endl;
	else
		cout << names[v[2].second] << endl;
	return 0;
}
