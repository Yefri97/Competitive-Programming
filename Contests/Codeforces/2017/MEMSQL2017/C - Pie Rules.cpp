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

const int oo = 1e9, mxn = 60;

int n;
int A[mxn], memo[mxn][2];

int solver(int id, int trn) {
	if (id == n) return 0;
	if (memo[id][trn] != -1) return memo[id][trn];
	int ans;
	if (trn)
		ans = max(solver(id + 1, trn), solver(id + 1, 1 - trn) + A[id]);
	else
		ans = min(solver(id + 1, trn) + A[id], solver(id + 1, 1 - trn));
	return memo[id][trn] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		fori(i, 0, n)
			cin >> A[i];
		int acc = accumulate(A, A + n, 0);
		memset(memo, -1, sizeof memo);
		int b = solver(0, 1);
		cout << acc - b << " " << b << endl;
	}
	return 0;
}