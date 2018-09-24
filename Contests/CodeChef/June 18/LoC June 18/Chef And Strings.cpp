#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010;

char ch[MN];
int l[MN], r[MN], p[MN];
int curr[26], freq[26][MN];

bool cmp(int a, int b) { return p[a] < p[b]; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> vs(n);
	fori(i, 0, n)
		cin >> vs[i];
	int m; cin >> m;
	fori(i, 0, m)
		cin >> l[i] >> r[i] >> p[i] >> ch[i];
	vi q(m);
	fori(i, 0, m) q[i] = i;
	sort(q.begin(), q.end(), cmp);
	fori(i, 0, m) p[i]--;
	memset(curr, -1, sizeof curr);
	vi ans(m);
	fori(i, 0, m) {
		int x = q[i], c = ch[x] - 'a';
		if (curr[c] != p[x]) {
			fori(i, 0, n)
				freq[c][i + 1] = (p[x] < vs[i].size() && vs[i][p[x]] == ch[x]);
			fori(i, 1, n + 1)
				freq[c][i] += freq[c][i - 1];
			curr[c] = p[x];
		}
		ans[x] = freq[c][r[x]] - freq[c][l[x] - 1];
	}
	fori(i, 0, m)
		cout << ans[i] << endl;
	return 0;
}
