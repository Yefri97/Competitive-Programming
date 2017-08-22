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

bool cmp(char a, char b) {
	if (tolower(a) == tolower(b)) return a < b;
	return tolower(a) < tolower(b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		sort(s.begin(), s.end(), cmp);
		do {
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end(), cmp));
	}
	return 0;
}