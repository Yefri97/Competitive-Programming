#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string orientations = "SWNE";

string values = "23456789TJQKA";
string suits = "CDSH";

struct card {

	string label;
	int value, suit;

	card() {}
	card(string c) {
		label = c;
		value = values.find(c[1]);
		suit = suits.find(c[0]);
	}

	bool operator < (const card &o) const {
		if (suit == o.suit)
			return value < o.value;
		return suit < o.suit;
	}

};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string start;
	while (cin >> start && start != "#") {
		string cards; cin >> cards;
		string cards2; cin >> cards2;
		cards += cards2;
		int c = (orientations.find(start) + 1) % 4;
		vector< vector<card> > ans(4);
		fori(i, 0, 52) {
			ans[c].push_back(card(cards.substr(2 * i, 2)));
			c = (c + 1) % 4;
		}
		fori(i, 0, 4) {
			cout << orientations[i] << ":";
			sort(ans[i].begin(), ans[i].end());
			fori(j, 0, ans[i].size())
				cout << " " << ans[i][j].label;
			cout << endl;
		}
	}
	return 0;
}
