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

const int oo = 1e9, mxn = 100;

char board[mxn][mxn];

bool check(string s, int k) {
	int ans = 1, it = 0;
	fori(i, 0, k)
		fori(j, 0, k)
			board[i][j] = s[i * k + j];
	fori(i, 0, k) {
		fori(j, 0, k) {
			ans &= (board[i][j] == s[it]);
			ans &= (board[j][i] == s[it]);
			ans &= (board[k - i - 1][k - j - 1] == s[it]);
			ans &= (board[k - j - 1][k - i - 1] == s[it]);
			it++;
		}
	}
	return ans;
}

int nextInt() {
	string num; getline(cin, num);
	return atoi(num.c_str());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = nextInt(), cs = 0;
	while (t--) {
		string input; getline(cin, input);
		string s;
		for (char c : input)
			if (isalpha(c)) s.push_back(c);
		int n = s.size(), ans = 1;
		cout << "Case #" << ++cs << ":" << endl;
		if (sqrt(n) == floor(sqrt(n)))
			ans = check(s, sqrt(n));
		else
			ans = 0;
		if (ans)
			cout << (int)sqrt(n) << endl;
		else
			cout << "No magic :(" << endl;
	}
	return 0;
}