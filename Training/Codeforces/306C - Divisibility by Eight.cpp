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

int memo[100][10];
int n;
string input, num;

int solver(int id, int rem) {
	if (id == n) return (num.size() > 0 && rem == 0);
	if (memo[id][rem] != -1) return memo[id][rem];
	num.push_back(input[id]);
	if (solver(id + 1, (rem * 10 + (input[id]-'0')) % 8)) return 1;
	num.pop_back();
	if (solver(id + 1, rem)) return 1;
	return memo[id][rem] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> input) {
		n = input.size();
		num.clear();
		memset(memo, -1, sizeof memo);
		int ans = solver(0, 0);
		if (ans) {
			cout << "YES" << endl;
			cout << num << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}