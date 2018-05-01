#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int val[] = {1, 3, 5, 7, 9};
int oudlers[] = {112, 102, 82, 72};
map<string, int> mapper = {{"jack", 1}, {"knight", 2}, {"queen", 3}, {"king", 4}};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	fori(t, 0, tc) {
		int n; cin >> n;
		cin.ignore();
		int cnt = 0, points = 0;
		fori(i, 0, n) {
			string card; getline(cin, card);
			if (card == "fool" || card == "one of trumps" || card == "twenty-one of trumps") {
				cnt++;
				points += 9;
			} else {
				int it = 0;
				while (card[it] != ' ') it++;
				string c = card.substr(0, it);
				points += val[mapper[c]];
			}
		}
		if (t) cout << endl;
		cout << "Hand #" << t + 1 << endl;
		if (oudlers[cnt] > points)
			cout << "Game lost by " << (oudlers[cnt] - points) / 2 << " point(s)." << endl;
		else
			cout << "Game won by " << (points - oudlers[cnt]) / 2 << " point(s)." << endl;
	}
	return 0;
}
