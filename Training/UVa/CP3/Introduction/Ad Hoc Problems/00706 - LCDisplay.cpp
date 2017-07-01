// Interesting Real Life Problems, Harder
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

int lcd[10][7] = {{1, 1, 1, 1, 1, 1, 0}, {0, 1, 1, 0, 0, 0, 0}, {1, 1, 0, 1, 1, 0, 1},
									{1, 1, 1, 1, 0, 0, 1}, {0, 1, 1, 0, 0, 1, 1}, {1, 0, 1, 1, 0, 1, 1},
									{1, 0, 1, 1, 1, 1, 1}, {1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1},
									{1, 1, 1, 1, 0, 1, 1}};

char board[25][120];

void print(int j, int s, int n) {
	int idx = j * (s + 3);
	if (lcd[n][0]) fori(i, 0, s) board[0][idx + i + 1] = '-';
	if (lcd[n][1]) fori(i, 0, s) board[i + 1][idx + s + 1] = '|';
	if (lcd[n][2]) fori(i, 0, s) board[s + i + 2][idx + s + 1] = '|';
	if (lcd[n][3]) fori(i, 0, s) board[2 * s + 2][idx + i + 1] = '-';
	if (lcd[n][4]) fori(i, 0, s) board[s + i + 2][idx] = '|';
	if (lcd[n][5]) fori(i, 0, s) board[i + 1][idx] = '|';
	if (lcd[n][6]) fori(i, 0, s) board[s + 1][idx + i + 1] = '-';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int s;
	string num;
	while (cin >> s >> num && s != 0) {
		memset(board, ' ', sizeof board);
		fori(i, 0, num.size())
			print(i, s, num[i] - '0');
		fori(i, 0, 2 * s + 3) {
			fori(j, 0, ((int)num.size()) * (s + 3) - 1)
				cout << board[i][j];
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}