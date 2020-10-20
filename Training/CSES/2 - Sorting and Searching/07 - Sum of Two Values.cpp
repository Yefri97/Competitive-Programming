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
const int MN = 200010;
 
int a[MN];
 
bool cmp(int i, int j) { return a[i] < a[j]; }
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	int n, k; cin >> n >> k;
	fori(i, 0, n) cin >> a[i];
	vi order(n);
	fori(i, 0, n) order[i] = i;
	sort(all(order), cmp);
	int l = 0, r = n - 1;
	while (r > l) {
		while (r > l && a[order[r]] + a[order[l]] < k)
			l++;
		if (r == l) break;
		if (a[order[r]] + a[order[l]] == k) {
			cout << order[l] + 1 << " " << order[r] + 1 << endl;
			return 0;
		}
		r--;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}