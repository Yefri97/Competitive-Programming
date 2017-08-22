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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vi freq(26);
	int k; cin >> k;
	string line; cin >> line;
	fori(i, 0, line.size())
		freq[line[i] - 'a']++;
	bool ans = true;
	fori(i, 0, 26)
		ans &= (freq[i] % k == 0);
	if (ans) {
		string s;
		fori(i, 0, 26)
			fori(j, 0, freq[i] / k)
				s.push_back(i + 'a');
		fori(i, 0, k)
			cout << s;
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}