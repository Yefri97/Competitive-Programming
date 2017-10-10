#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 102000;

int mx[] = {0, -1, -1, 0,  1, 1, 0};
int my[] = {1, 1, 0, -1, -1, 0, 1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	vector<ii> ans(mxn);
	ans[1] = ii(0, 0);
	ans[2] = ii(0, 1);
	ans[3] = ii(-1, 1);
	ans[4] = ii(-1, 0);
	ans[5] = ii(0, -1);
	ans[6] = ii(1, -1);
	int x = 1, y = -1, it = 6;
	for (int i = 1; it < mxn; i++) {
		int steps[] = {2, i, i + 1, i + 1, i + 1, i + 1, i};
		fori(k, 0, 7) {
			fori(j, 0, steps[k]) {
				x += mx[k];
				y += my[k];
				ans[++it] = ii(x, y);
			}
		}
	}
	int n;
	while (cin >> n)
		cout << ans[n].first << " " << ans[n].second << endl;
	return 0;
}