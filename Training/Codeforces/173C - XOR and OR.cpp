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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b; cin >> a >> b;
	bool onea = false;
	fori(i, 0, a.size())
		if (a[i] == '1') onea = true;
	bool oneb = false;
	fori(i, 0, b.size())
		if (b[i] == '1') oneb = true;
	cout << (a.size() == b.size() && !(onea ^ oneb) ? "YES" : "NO") << endl;
	return 0;
}