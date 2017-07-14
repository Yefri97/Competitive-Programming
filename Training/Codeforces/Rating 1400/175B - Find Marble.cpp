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

const int oo = 1e9, mxn = 100010;
int A[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, s, t; cin >> n >> s >> t; s--; t--;
	fori(i, 0, n)
		cin >> A[i];
	vector<bool> visited(n);
	int ans = 0, curr = s;
	while (curr != t) {
		curr = A[curr]-1;
		if (visited[curr]) break;
		visited[curr] = true;
		ans++;
	}
	cout << (curr == t ? ans : -1) << endl;
	return 0;
}