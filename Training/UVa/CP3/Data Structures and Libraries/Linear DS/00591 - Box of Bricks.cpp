// 1D Array Manipulation
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

const int INF = 1e9, MAXN = 55;

int input[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, cs = 0;
	while (cin >> n && n) {
		cout << "Set #" << ++cs << endl;
		fori(i, 0, n)
			cin >> input[i];
		int h = accumulate(input, input + n, 0) / n;
		int result = 0;
		fori(i, 0, n)
			result += abs(h - input[i]);
		cout << "The minimum number of moves is " << result / 2 << "." << endl;
		cout << endl;
	}
	return 0;
}