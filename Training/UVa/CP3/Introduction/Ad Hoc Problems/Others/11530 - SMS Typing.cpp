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

int kb[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string n; getline(cin, n);
	int t = atoi(n.c_str()), cs = 0;
	while (t--) {
		string line; getline(cin, line);
		int ans = 0;
		fori(i, 0, line.size()) {
			char c = line[i];
			if (c == ' ') ans++;
			else ans += kb[c-'a'];
		}
		cout << "Case #" << ++cs << ": " << ans << endl;
	}
	return 0;
}