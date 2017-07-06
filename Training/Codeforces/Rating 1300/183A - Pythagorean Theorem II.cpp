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
	vi sq;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		sq.push_back(i * i);
	int ans = 0;
	fori(i, 0, n)
		fori(j, 0, i)
			if (binary_search(sq.begin(), sq.end(), sq[i] + sq[j]))
				ans++;
	cout << ans << endl;
	return 0;
}