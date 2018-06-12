#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool check(string s, int p) {
	int n = s.size();
	fori(i, 0, n - p)
		if (s[i] != s[i + p])
			return true;
	return false;
}

void fix(string &s, int a, int b) {
	if (s[a] == '.' || s[b] == '.') {
		if (s[a] == '.' && s[b] != '.') s[a] = (s[b] == '0' ? '1' : '0');
		else if (s[a] != '.' && s[b] == '.') s[b] = (s[a] == '0' ? '1' : '0');
		else s[a] = '0', s[b] = '1';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, p; cin >> n >> p;
	string s; cin >> s;
	if (2 * p < n) {
		fori(i, 0, p) {
			fori(j, i + p, n - p) {
				fix(s, j, j - p);
				fix(s, j, j + p);
			}
		}
	} else {
		fori(i, 0, n - p) {
			fix(s, i, i + p);
		}
	}
	fori(i, 0, n) {
		if (s[i] == '.')
			s[i] = '0';
	}
	cout << (check(s, p) ? s : "NO") << endl;
	return 0;
}
