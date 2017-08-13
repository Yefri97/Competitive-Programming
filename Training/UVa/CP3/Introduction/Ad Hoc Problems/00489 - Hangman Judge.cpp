#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n != -1) {
		string s, t; cin >> s >> t;
		set<char> puzzle, said;
		for (char c : s)
			puzzle.insert(c);
		int ans = -1, stroke = 0;
		for (char c : t) {
			if (said.find(c) != said.end()) continue;
			if (puzzle.find(c) != puzzle.end()) {
				puzzle.erase(c);
				said.insert(c);
			} else {
				stroke++;
			}
			if (stroke == 7) ans = 0;
			if (puzzle.empty()) ans = 1;
			if (ans != -1) break;
		}
		cout << "Round " << n << endl;
		if (ans == -1)
			cout << "You chickened out." << endl;
		else if (ans == 0)
			cout << "You lose." << endl;
		else
			cout << "You win." << endl;
	}
	return 0;
}