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

const int oo = 1e9, mxn = 50;

ll A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	A[0] = 0; A[1] = 1;
	fori(i, 2, mxn)
		A[i] = A[i-1] + A[i-2] + 1;
	int n;
	while (cin >> n && n != -1)
		cout << A[n] << " " << A[n+1] << endl;
	return 0;
}