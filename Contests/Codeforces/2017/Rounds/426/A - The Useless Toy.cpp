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

char dir[] = {'^', '>', 'v', '<'};

int getid(char c) {
	fori(i, 0, 4) if (dir[i] == c) return i;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	char a, b; cin >> a >> b;
	int n; cin >> n;
	int x = getid(a), y = getid(b);
	bool ba = (mod(x + n, 4) == y), bb = (mod(x - n, 4) == y);
	cout << (ba && bb ? "undefined" : ba ? "cw" : "ccw") << endl;
	return 0;
}