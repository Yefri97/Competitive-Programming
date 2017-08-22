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

const int oo = 1e9, mxn = 100;

string a, b;
int memo[mxn][mxn];

int solver(int n, int m) {
    if (n == -1 || m == -1) return 0;
    if (memo[n][m] != -1) return memo[n][m];
    if (a[n] == b[m]) return memo[n][m] = solver(n - 1, m - 1) + 1;
    return memo[n][m] = max(solver(n - 1, m), solver(n, m - 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int cs = 0;
    while (getline(cin, a) && a != "#") {
        getline(cin, b);
        memset(memo, -1, sizeof memo);
        int ans = solver(a.size() - 1, b.size() - 1);
        cout << "Case #" << ++cs << ": you can visit at most " << ans << " cities." << endl;
    }
	return 0;
}