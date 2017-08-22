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

int A[60];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		fori(i, 0, n)
			cin >> A[i];
		int cnt = 0;
		fori(i, 0, n)
			fori(j, 0, i)
				cnt += (__gcd(A[i], A[j]) == 1);
		if (cnt == 0) {
			cout << "No estimate for this data set." << endl;
		} else {
			cout << fixed << setprecision(6) << sqrt((n * (n - 1) * 3.0) / cnt) << endl;
		}
	}
	return 0;
}