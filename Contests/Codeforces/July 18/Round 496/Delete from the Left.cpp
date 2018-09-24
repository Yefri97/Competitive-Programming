#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b; cin >> a >> b;
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 && j >= 0 && a[i] == b[j]) i--, j--;
	int ans = (i + j + 2);
	cout << ans << endl;
	return 0;
}
