#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define SZ(X) ((int)X.size())
#define SQ(X) ((X) * (X))
#define all(X) X.begin(), X.end()
#define fori(i,a,b) for(int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;
const int MN = 1e6 + 1;

int freq[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n; cin >> n;
	fori(i, 0, n) {
		int x; cin >> x;
		freq[x]++;
	}
	int ans = 1;
	for (int i = 2; i < MN; i++) {
		int cnt = 0;
		for (int j = i; j < MN; j += i)
			cnt += freq[j];
		if (cnt >= 2) ans = i;
	}
	cout << ans << endl;
	return 0;
}
