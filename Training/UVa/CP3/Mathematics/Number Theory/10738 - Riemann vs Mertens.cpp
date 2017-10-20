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

const int oo = 1e9, mxn = 1000001;

int A[mxn], B[mxn], mu[mxn], M[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fori(i, 0, mxn) A[i] = i;
	for (int i = 2; i < mxn; i++) if (B[i] == 0) {
		for (int j = i; j < mxn; j += i) {
			A[j] /= i;
			B[j]++;
		}
	}
	mu[1] = M[1] = 1;
	fori(i, 2, mxn) {
		mu[i] = (A[i] != 1 ? 0 : B[i] % 2 ? -1 : 1);
		M[i] = mu[i] + M[i - 1];
	}
	int n;
	while (cin >> n && n)
		cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
	return 0;
}