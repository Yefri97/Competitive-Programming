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

int A[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string line; cin >> line;
		int n = line.size();
		A[0] = (line[0] == 'O');
		fori(i, 1, n)
			A[i] = (line[i] == 'X' ? 0 : A[i - 1] + 1);
		int acc = accumulate(A, A + n, 0);
		cout << acc << endl;
	}
	return 0;
}