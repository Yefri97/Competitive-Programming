#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int f(int n, int k) {
	if (n == 1) return 1;
	return (f(n - 1, k) + k - 1) % n + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n && n) {
		int m = 1;
		while (f(n - 1, m) % n + 1 != 2) m++;
		cout << m << endl;
	}
	return 0;
}
