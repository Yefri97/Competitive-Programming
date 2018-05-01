#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

const int oo = 1e9;

string values = "23456789TJQKA";
string suits = "CDHS";

struct Hand {

	vi vals;
	vector< vi > cards;

	Hand() {}

	Hand(vector<string> v) {
		cards.assign(4, vi());
		for (string s : v) {
			int a = values.find(s[0]), b = suits.find(s[1]);
			cards[b].push_back(a);
			vals.push_back(a);
		}
		sort(vals.begin(), vals.end());
		fori(i, 0, 4) sort(cards[i].begin(), cards[i].end());
	}

	vi r8() {
		int id = -1;
		if (vals[0] == vals[1]) id = 0;
		if (vals[1] == vals[2]) id = 1;
		if (vals[2] == vals[3]) id = 2;
		if (vals[3] == vals[4]) id = 3;
		vi res;
		if (id != -1) {
			fori(i, 0, 5)
				if (i != id && i != id + 1)
					res.push_back(vals[i]);
		} else {
			res.push_back(-1);
		}
		return res;
	}

	vi r7() {
		if (vals[0] == vals[1] && vals[2] == vals[3]) {
			vi res = {vals[2], vals[0], vals[4]};
			return res;
		}
		if (vals[1] == vals[2] && vals[3] == vals[4]) {
			vi res = {vals[3], vals[1], vals[0]};
			return res;
		}
		if (vals[0] == vals[1] && vals[3] == vals[4]) {
			vi res = {vals[3], vals[0], vals[2]};
			return res;
		}
		vi res = {-1, -1, -1};
		return res;
	}

	int r6() {
		if (vals[0] == vals[2]) return vals[0];
		if (vals[1] == vals[3]) return vals[1];
		if (vals[2] == vals[4]) return vals[2];
		return -1;
	}

	int r5() {
		if (vals[4] == vals[0] + 4) return vals[4];
		return -1;
	}

	int r4() {
		for (vi c : cards)
			if (c.size() == 5)
				return 1;
		return -1;
	}

	int r3() {
		if (vals[0] == vals[2] && vals[3] == vals[4]) return vals[0];
		if (vals[0] == vals[1] && vals[2] == vals[4]) return vals[2];
		return -1;
	}

	int r2() {
		if (vals[0] == vals[3]) return vals[0];
		if (vals[1] == vals[4]) return vals[1];
		return -1;
	}

	int r1() {
		for (vi c : cards) {
			if (c.size() < 5) continue;
			if (c[4] == c[0] + 4) return c[4];
		}
		return -1;
	}

	bool operator > (Hand o) {
		int x, y;
		
		x = r1();
		y = o.r1();
		if (x != y) return x > y;

		x = r2();
		y = o.r2();
		if (x != y) return x > y;

		x = r3();
		y = o.r3();
		if (x != y) return x > y;

		x = r4();
		y = o.r4();
		if (x == 1 && y == 1) {
			fori(i, 0, 5)
				if (vals[4 - i] != o.vals[4 - i])
					return vals[4 - i] > o.vals[4 - i];
		} else if (x * y < 0) {
			return x > y;
		}

		x = r5();
		y = o.r5();
		if (x != y) return x > y;

		x = r6();
		y = o.r6();
		if (x != y) return x > y;

		vi xx, yy;
		xx = r7();
		yy = o.r7();
		if (xx != yy) return xx > yy;

		xx = r8();
		yy = o.r8();
		if (xx != yy) return xx > yy;

		fori(i, 0, 5)
			if (vals[4 - i] != o.vals[4 - i])
				return vals[4 - i] > o.vals[4 - i];
		return false;
	}

};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<string> v(5);
	while (cin >> v[0] && v[0] != "") {
		fori(i, 1, 5)
			cin >> v[i];
		Hand black = Hand(v);
		fori(i, 0, 5)
			cin >> v[i];
		Hand white = Hand(v);
		if (black > white) {
			cout << "Black wins." << endl;
		} else if (white > black) {
			cout << "White wins." << endl;
		} else {
			cout << "Tie." << endl;
		}
	}
	return 0;
}
