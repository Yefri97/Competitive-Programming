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
int color[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(color, -1, sizeof color);
	int n, m; cin >> n >> m;
	while (m--) {
		int A[3]; cin >> A[0] >> A[1] >> A[2]; A[0]--; A[1]--; A[2]--;
		int i = 0;
		while (i < 3) {
			if (color[A[i]] != -1) {
				color[A[(i+1)%3]] = (color[A[i]]+1)%3;
				color[A[(i+2)%3]] = (color[A[i]]+2)%3;
				break;
			}
			i++;
		}
		if (i == 3) {
			fori(i, 0, 3)
				color[A[i]] = i;
		}
	}
	fori(i, 0, n)
		cout << color[i] + 1 << " ";
	cout << endl;
	return 0;
}