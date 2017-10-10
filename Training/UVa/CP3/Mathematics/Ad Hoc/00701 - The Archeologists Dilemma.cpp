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

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		int nd = log10(n) + 1;
		int t = nd + 1, low, high;
		while (true) {
			low = ceil(t / log10(2) + log2(n));
			high = floor(t / log10(2) + log2(n + 1));
			if (low <= high) break;
			t++;
		}
		cout << low << endl;
	}
	return 0;
}