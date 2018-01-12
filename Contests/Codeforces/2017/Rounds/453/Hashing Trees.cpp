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

const int oo = 1e9, MX = 200010;

int A[MX], p[MX];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n + 1)
		cin >> A[i];
	bool f = true;
	fori(i, 0, n)
		f &= A[i] == 1 || A[i + 1] == 1;
	if (f) {
		cout << "perfect" << endl;
	} else {
		cout << "ambiguous" << endl;
		int u = 0, id = 0;
		fori(i, 0, n + 1) {
			fori(j, 0, A[i])
				p[id++] = u;
			u = id;
		}
		fori(i, 0, id)
			cout << p[i] << " ";
		cout << endl;
		int it = 0, v = 0;
		while (A[it] == 1 || A[it + 1] == 1) {
			v += A[it];
			it++;
		}
		v += A[it];
		p[v] = v - 1;
		fori(i, 0, id)
			cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}