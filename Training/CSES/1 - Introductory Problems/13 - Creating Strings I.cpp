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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef UTP
	freopen("input.txt", "r", stdin);
	#endif
	string s; cin >> s;
	sort(all(s));
	vector<string> ans;
	do {
		ans.push_back(s);
	} while (next_permutation(all(s)));
	cout << SZ(ans) << endl;
	for (string x : ans)
		cout << x << endl;
	return 0;
}
