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
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

bool check(string p, string a, string b) {
	int it = 0;
	stack<char> st;
	string ans;
	fori(i, 0, p.size()) {
		if (p[i] == 'i') {
			st.push(a[it++]);
		} else {
			if (st.empty()) return false;
			ans.push_back(st.top()); st.pop();
		}
	}
	return ans == b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string a, b; cin >> a >> b;
		string pattern = "iiiioooo";
		cout << "Output for " << a << " " << b << endl;
		cout << "[" << endl;
		do {
			if (check(pattern, a, b)) {
				cout << pattern[0];
				fori(i, 1, 8)
					cout << " " << pattern[i];
				cout << endl;
			}
		} while (next_permutation(pattern.begin(), pattern.end()));
		cout << "]" << endl;
	}
	return 0;
}