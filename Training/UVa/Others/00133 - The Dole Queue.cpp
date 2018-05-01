#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	while (cin >> n >> a >> b && n) {
		vector<int> l(n), r(n);
		fori(i, 0, n) {
			l[i] = (i - 1 + n) % n;
			r[i] = (i + 1) % n;
		}
		int it1 = n - 1, it2 = 0, cnt = n;
		while (cnt) {
			fori(i, 0, a) it1 = r[it1];
			fori(i, 0, b) it2 = l[it2];
			r[l[it1]] = r[it1];
			l[r[it1]] = l[it1];
			cnt--;
			if (it1 != it2) {
				r[l[it2]] = r[it2];
				l[r[it2]] = l[it2];
				cnt--;
			}
			cout << setw(3) << it1 + 1;
			if (it1 != it2) cout << setw(3) << it2 + 1;
			if (cnt > 0) cout << ",";
			if (r[it1] == it2) swap(it1, it2);
		}
		cout << endl;
	}
	return 0;
}