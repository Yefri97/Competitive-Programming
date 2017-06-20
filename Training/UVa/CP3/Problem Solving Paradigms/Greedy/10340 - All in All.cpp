// Non Classical, Usually Harder
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
	string a, b;
	while (cin >> a >> b) {
		int i = 0, j = 0;
		while (i < b.size()) {
			if (a[j] == b[i])
				j++;
			if (j == a.size()) break;
			i++;
		}
		cout << (j == a.size() ? "Yes" : "No") << endl;
	}
	return 0;
}