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

const int INF = 1e9, MAXN = 110;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	A[n] = A[0];
	int min_val = 10000, a, b;
	fori(i, 0, n) {
		if (abs(A[i] - A[i + 1]) < min_val) {
			min_val = abs(A[i] - A[i + 1]);
			a = i, b = i + 1;
		}
	}
	cout << a + 1 << " " << (b % n) + 1 << endl;
	return 0;
}