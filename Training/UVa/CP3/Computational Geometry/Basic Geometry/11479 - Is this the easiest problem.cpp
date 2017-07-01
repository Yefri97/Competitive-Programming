// Triangles
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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll A[5];
	int n, cs = 0; cin >> n;
	while (n--) {
		cout << "Case " << ++cs << ": ";
		cin >> A[0] >> A[1] >> A[2];
		sort(A, A + 3);
		if (A[0] <= 0 || A[1] <= 0 || A[2] <= 0 || A[0] + A[1] <= A[2]) {
			cout << "Invalid" << endl;
		} else if (A[0] == A[1] && A[1] == A[2]) {
			cout << "Equilateral" << endl;
		} else if (A[0] == A[1] || A[1] == A[2] || A[0] == A[2]) {
			cout << "Isosceles" << endl;
		} else {
			cout << "Scalene" << endl;
		}
	}
	return 0;
}