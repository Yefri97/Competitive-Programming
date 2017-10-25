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
	string n;
	while (cin >> n) {
		vi freq(10);
		fori(i, 0, (int)n.size())
			freq[n[i] - '0']++;
		ll max_val = 0;
		fori(i, 0, 10)
			fori(j, 0, freq[9 - i])
				max_val = max_val * 10 + (9 - i);
		int it = 1;
		while (freq[it] == 0) it++;
		freq[it]--;
		ll min_val = it;
		fori(i, 0, 10)
			fori(j, 0, freq[i])
				min_val = min_val * 10 + i;
		ll d = max_val - min_val;
		cout << max_val << " - " << min_val << " = " << d << " = " << "9 * " << d / 9 << endl;
	}
	return 0;
}