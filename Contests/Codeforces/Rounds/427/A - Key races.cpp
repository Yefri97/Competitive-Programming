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
	int n, v1, v2, t1, t2; cin >> n >> v1 >> v2 >> t1 >> t2;
	int a = n * v1 + 2 * t1, b = n * v2 + 2 * t2;
	cout << (a == b ? "Friendship" : a < b ? "First" : "Second") << endl;
	return 0;
}