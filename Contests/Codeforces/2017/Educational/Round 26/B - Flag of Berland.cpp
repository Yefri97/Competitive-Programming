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

const int oo = 1e9, mxn = 110;

bool check(int A[mxn][mxn], int n, int m) {
	if (n % 3) return false;
	set<char> st;
	int h = n / 3;
	fori(k, 0, 3) {
		char color = A[h*k][0];
		st.insert(color);
		fori(i, 0, h)
			fori(j, 0, m)
				if (A[h*k+i][j] != color) return false;
	}
	if (st.size() != 3) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int flagA[mxn][mxn], flagB[mxn][mxn];
	int n, m; cin >> n >> m;
	fori(i, 0, n) {
		fori(j, 0, m) {
			char c; cin >> c;
			flagA[i][j] = flagB[j][i] = c;
		}
	}
	bool a = check(flagA, n, m), b = check(flagB, m, n);
	cout << (a || b ? "YES" : "NO") << endl;
	return 0;
}