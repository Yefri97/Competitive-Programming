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

int mmax[110];
char ans[110][55];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n = s.size(), low = 0, high = -1, k = 0;
		fori(i, 0, n) {
			char c = s[i];
			if (c == 'R') {
				high = max(high, k);
				mmax[55 + k] = i;
				k++;
			} else if (c == 'C') {
				high = max(high, k);
				low = min(low, k);
				mmax[55 + k] = i;
			} else {
				k--;
				low = min(low, k);
				mmax[55 + k] = i;
			}
		}
		memset(ans, ' ', sizeof ans);
		int i = -low, j = 1;
		for (char c : s) {
			if (c == 'R') {
				ans[i][j] = '/';
				i++;
			} else if (c == 'C') {
				ans[i][j] = '_';
			} else {
				i--;
				ans[i][j] = '\\';
			}
			j++;
		}
		cout << "Case #" << ++cs << ":" << endl;
		int h = high - low + 1;
		for (int i = high; i >= low; i--) {
			cout << "|";
			for (int j = 0; j <= mmax[55 + i] + 1; j++)
				cout << ans[i - low][j];
			cout << endl;
		}
		cout << "+"; fori(i, 0, n + 2) cout << "-"; cout << endl;
		cout << endl;
	}
	return 0;
}