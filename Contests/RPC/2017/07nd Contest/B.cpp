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

const int oo = 1e9, mxn = 15;

string names[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		queue<int> q;
		fori(i, 0, n) {
			cin >> names[i];
			q.push(i);
		}
		string line; cin >> line;
		int dynasty = 0;
		vi score(2);
		for (char c : line) {
			int winner = (c == 'B'), loser = !winner;
			score[winner]++;
			score[loser] = 0;
			dynasty = max(dynasty, score[winner]);
		}
		vvi teams(2, vi(2));
		fori(j, 0, 2) {
			fori(i, 0, 2) {
				int id = q.front(); q.pop();
				teams[i][j] = id;
			}
		}
		score.assign(2, 0);
		vii init(2), ans;
		fori(i, 0, 2) init[i] = ii(teams[i][0], teams[i][1]);
		for (char c : line) {
			int winner = (c == 'B'), loser = !winner;
			score[winner]++;
			score[loser] = 0;
			// Winner
			swap(teams[winner][0], teams[winner][1]);
			// Loser
			int nxt = q.front(); q.pop();
			q.push(teams[loser][1]);
			teams[loser][1] = nxt;
			init[loser] = ii(teams[loser][0], teams[loser][1]);
			swap(teams[loser][0], teams[loser][1]);
			// Check dynasty
			if (score[winner] == dynasty)
				ans.push_back(init[winner]);
		}
		for (auto team : ans)
			cout << names[team.first] << " " << names[team.second] << endl;
	}
	return 0;
}