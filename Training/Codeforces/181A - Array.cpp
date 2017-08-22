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
int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	int idxneg = 0;
	while (A[idxneg] >= 0) idxneg++;
	cout << 1 << " " << A[idxneg] << endl;
	int idxpos = 0, idxneg1 = -1, idxneg2 = -1;
	while (idxpos < n && A[idxpos] <= 0) idxpos++;
	if (idxpos < n) {
		cout << 1 << " " << A[idxpos] << endl;
		cout << n - 2;
	} else {
		idxneg1 = idxneg + 1;
		cout << 2 << " ";
		while (A[idxneg1] >= 0) idxneg1++;
		cout << A[idxneg1] << " ";
		idxneg2 = idxneg1 + 1;
		while (A[idxneg2] >= 0) idxneg2++;
		cout << A[idxneg2] << endl;
		cout << n - 3;
	}
	fori(i, 0, n)
		if (i != idxneg && i != idxpos && i != idxneg1 && i != idxneg2)
			cout << " " << A[i];
	cout << endl;
	return 0;
}