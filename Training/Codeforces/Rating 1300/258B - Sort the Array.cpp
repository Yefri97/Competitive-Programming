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

const int INF = 1e9, MAXN = 100010;
int A[MAXN];
int n, l, r;

bool check() {
	int it = 1;
	while (it < n && A[it - 1] < A[it]) it++;
	if (it == n) {
		l = 0; r = 0;
		return true;
	}
	l = it - 1;
	while (it < n && A[it - 1] > A[it]) it++;
	r = it - 1;
	while (it < n && A[it - 1] < A[it]) it++;
	return it == n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n)
		cin >> A[i];
	bool can = check();
	if (can) {
		if ((l == 0 || (A[r] > A[l - 1])) && (r == n - 1 || (A[l] < A[r + 1]))) {
			cout << "yes" << endl;
			cout << l + 1 << " " << r + 1 << endl;
		} else {
			cout << "no" << endl;
		}
	} else {
		cout << "no" << endl;
	}
	return 0;
}