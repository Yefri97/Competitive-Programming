// Fibonacci Numbers
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

const int INF = 1e9, MAXN = 60;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	A[0] = 1; A[1] = 2;
	fori(i, 2, 60)
		A[i] = A[i - 1] + A[i - 2];
	int n;
	while (cin >> n && n) {
		cout << A[n - 1] << endl;
	}
	return 0;
}