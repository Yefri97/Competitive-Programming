#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	s.push_back('_');
	int max_len = 0, cnt = 0;
	for (int i = 0, st = 0, len; i < (int)s.size(); i++) {
		char c = s[i];
		if (st == 0) {
			if (isalpha(c)) {
				st = 1;
				len = 1;
			} else if (c == '_') {
				st = 0;
			} else if (c == '(') {
				st = 2;
			}
		} else if (st == 1) {
			if (isalpha(c)) {
				st = 1;
				len++;
			} else if (c == '_') {
				max_len = max(max_len, len);
				st = 0;
			} else if (c == '(') {
				max_len = max(max_len, len);
				st = 2;
			}
		} else if (st == 2) {
			if (isalpha(c)) {
				st = 3;
				cnt++;
			} else if (c == '_') {
				st = 2;
			} else if (c == ')') {
				st = 0;
			}
		} else if (st == 3) {
			if (isalpha(c)) {
				st = 3;
			} else if (c == '_') {
				st = 2;
			} else if (c == ')') {
				st = 0;
			}
		}
	}
	cout << max_len << " " << cnt << endl;
	return 0;
}