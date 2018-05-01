#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string values = "23456789TJQKA";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	for (int t = 0; t < tc; t++) {
		deque<string> deck;
		fori(i, 0, 52) {
			string card; cin >> card;
			deck.push_back(card);
		}
		deque<string> hand;
		fori(i, 0, 25) {
			hand.push_front(deck.back());
			deck.pop_back();
		}
		int y = 0;
		fori(i, 0, 3) {
			string c = deck.back(); deck.pop_back();
			int x = min(10, (int)values.find(c[0]) + 2);
			y += x;
			fori(i, 0, 10 - x)
				deck.pop_back();
		}
		fori(i, 0, 25) {
			deck.push_back(hand.front());
			hand.pop_front();
		}
		fori(i, 0, y - 1)
			deck.pop_front();
		cout << "Case " << t + 1 << ": " << deck.front() << endl;
	}
	return 0;
}
