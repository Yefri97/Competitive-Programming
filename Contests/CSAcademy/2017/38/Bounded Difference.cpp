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

const int oo = 1e9, mxn = 100010;
int A[mxn];
int n, k;
vii err;

bool can(int i, int j) {
	bool ans = true;
	ans &= (i == 0 || abs(A[i-1] - A[j]) <= k) && (i == n - 1 || abs(A[i+1] - A[j]) <= k);
	ans &= (j == 0 || abs(A[j-1] - A[i]) <= k) && (j == n - 1 || abs(A[j+1] - A[i]) <= k);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	fori(i, 0, n)
		cin >> A[i];
	fori(i, 0, n - 1) {
		if (abs(A[i] - A[i + 1]) > k) {
			if (i + 2 < n && abs(A[i + 1] - A[i + 2]) > k)
				err.push_back(ii(2, i + 1)), i++;
			else
				err.push_back(ii(1, i));
		}
	}
	if (err.size() == 0) {
		cout << 0 << endl;
	} else if (err.size() > 2) {
		cout << -1 << endl;
	} else if (err.size() == 1) {
		int x = -1, y = -1;
		if (err[0].first == 2) {
			fori(i, 0, n)
				if (can(err[0].second, i))
					x = err[0].second, y = i;
		} else {
			fori(i, 0, n) if (i != err[0].second + 1)
				if (can(err[0].second, i))
					x = err[0].second, y = i;
			fori(i, 0, n) if (i != err[0].second)
				if (can(err[0].second + 1, i))
					x = err[0].second + 1, y = i;
		}
		if (x == -1 || y == -1)
			cout << -1 << endl;
		else
			cout << x + 1 << " " << y + 1 << endl;
	} else {
		vi a, b;
		a.push_back(err[0].second);
		if (err[0].first == 1) a.push_back(err[0].second + 1);
		b.push_back(err[1].second);
		if (err[1].first == 1) b.push_back(err[1].second + 1);
		int x = -1, y = -1;
		fori(i, 0, a.size())
			fori(j, 0, b.size())
				if (can(a[i], b[j]))
					x = a[i], y = b[j];
		if (x == -1 || y == -1)
			cout << -1 << endl;
		else
			cout << x + 1 << " " << y + 1 << endl;
	}
}