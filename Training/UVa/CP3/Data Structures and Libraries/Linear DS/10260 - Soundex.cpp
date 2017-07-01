// 1D Array Manipulation
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

map<char, int> mapper = {	{'B', 1}, {'F', 1}, {'P', 1}, {'V', 1},
													{'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2},
													{'D', 3}, {'T', 3},
													{'L', 4},
													{'M', 5}, {'N', 5},
													{'R', 6} };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	while (cin >> s) {
		int curr = -1;
		fori(i, 0, s.size()) {
			char c = s[i];
			int id = mapper[c];
			if (id == 0) {
				curr = -1;
			} else if (id != curr) {
				cout << id;
				curr = id;
			}
		}
		cout << endl;
	}
	return 0;
}