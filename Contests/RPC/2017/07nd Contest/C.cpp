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
	string a, b, s; cin >> a >> b;
	fori(i, 0, min(a.size(), b.size()))
		s.push_back(mod((a[i] - 'A') - (b[i] - 'A'), 26) + 'A');
	fori(i, b.size(), a.size())
		s.push_back(mod((a[i] - 'A') - (s[i - b.size()] - 'A'), 26) + 'A');
	cout << s << endl;
	return 0;
}