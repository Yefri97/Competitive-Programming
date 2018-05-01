#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string values[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<vi> shuffles(n, vi(52));
		fori(i, 0, n)
			fori(j, 0, 52)
				cin >> shuffles[i][j];
		cin.ignore();
		string sk;
		vi hand(52);
		fori(i, 0, 52) hand[i] = i;
		while (getline(cin, sk) && sk != "") {
			int k = atoi(sk.c_str()); k--;
			vi tmp = hand;
			fori(i, 0, 52)
				hand[i] = tmp[shuffles[k][i] - 1];
		}
		fori(i, 0, 52)
			cout << values[hand[i] % 13] << " of " << suits[hand[i] / 13] << endl;
		if (tc) cout << endl;
	}
	return 0;
}
