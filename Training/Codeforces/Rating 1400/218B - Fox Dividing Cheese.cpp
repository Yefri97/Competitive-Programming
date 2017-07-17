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
int A[5], B[5];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a, b; cin >> a >> b;
	while (a % 2 == 0) a /= 2, A[0]++;
	while (a % 3 == 0) a /= 3, A[1]++;
	while (a % 5 == 0) a /= 5, A[2]++;

	while (b % 2 == 0) b /= 2, B[0]++;
	while (b % 3 == 0) b /= 3, B[1]++;
	while (b % 5 == 0) b /= 5, B[2]++;

	if (a != b)
		cout << -1 << endl;
	else
		cout << abs(A[0] - B[0]) + abs(A[1] - B[1]) + abs(A[2] - B[2]) << endl;
	return 0;
}