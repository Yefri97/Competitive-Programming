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

const int oo = 1e9, MAXN = 110;
int A[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(j, 0, n)
		fori(i, 0, n)
			A[(j + i) % n][j] = n * j + i + 1;
	fori(i, 0, n) {
		fori(j, 0, n) 
			cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}